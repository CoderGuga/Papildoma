#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <set>
#include <regex>
#include <string>
#include <algorithm>
#include <cctype>

std::string normalizeWord(const std::string& word) {
    std::string result;
    for (char ch : word) {
        if (std::isalpha(static_cast<unsigned char>(ch)) || std::isdigit(static_cast<unsigned char>(ch))) {
        result += std::tolower(static_cast<unsigned char>(ch));
        }
    }
    return result;
}

int main() {
    std::ifstream infile("input.txt");
    if (!infile) {
        std::cerr << "Nepavyko atidaryti input.txt\n";
        return 1;
    }

    std::ofstream wordOut("xref_output.txt");
    std::ofstream urlOut("urls_output.txt");

    if (!wordOut || !urlOut) {
        std::cerr << "Nepavyko atidaryti išvesties failų\n";
        return 1;
    }

    std::unordered_map<std::string, std::set<int>> wordLines;
    std::unordered_map<std::string, int> wordCount;
    std::set<std::string> foundUrls;

    std::string line;
    int lineNumber = 0;

    // URL regex: matches http(s), www., or plain domains
    std::regex urlRegex(R"((https?://)?(www\.)?[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}(/\S*)?)");

    while (std::getline(infile, line)) {
        ++lineNumber;

        // --- Word processing ---
        std::stringstream ss(line);
        std::string word;

        while (ss >> word) {
            std::string cleaned = normalizeWord(word);
            if (!cleaned.empty()) {
                wordLines[cleaned].insert(lineNumber);
                wordCount[cleaned]++;
            }
        }

        // --- URL processing ---
        std::sregex_iterator begin(line.begin(), line.end(), urlRegex);
        std::sregex_iterator end;

        for (auto it = begin; it != end; ++it) {
            foundUrls.insert(it->str());
        }
    }

    infile.close();

    // Output word cross-reference table
    for (const auto& [word, lines] : wordLines) {
        if (wordCount[word] > 1) {
            wordOut << word << " (x" << wordCount[word] << ") → eilutės: ";
            for (auto it = lines.begin(); it != lines.end(); ++it) {
                if (it != lines.begin()) wordOut << ", ";
                wordOut << *it;
            }
            wordOut << "\n";
        }
    }

    // Output all found URLs
    for (const auto& url : foundUrls) {
        urlOut << url << "\n";
    }

    wordOut.close();
    urlOut.close();

    std::cout << "Apdorota: žodžiai → xref_output.txt, URL'ai → urls_output.txt\n";
    return 0;
}
