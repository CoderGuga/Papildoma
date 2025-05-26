# Papildoma

Programa išrenka visus pasikartojančius žodžius iš duoto "input.txt" failo ir išrašo juos į "xref_output.txt" failą, bei duoda eilutes (paragrafus) kuriuose tie žodžiai buvo.

Programa taip pat išrenka ir išrašo visus URL'us į "urls_output.txt" failą.


1. Sistemos Reikalavimai

Įsitikinkite, kad turite šias priemones:

Operacinė sistema: Windows, Linux arba macOS

C++ kompiliatorius: GCC (MinGW Windows sistemai), Clang arba MSVC

CMake: 3.10 ar naujesnė versija

Git: 2.0 ar naujesnė versija

Patikrinkite, ar įrankiai įdiegti:

          cmake --version
          gcc --version
          git --version


2. Projekto Atsisiuntimas


     Atidarykite terminalą (arba "Command Prompt" Windows sistemoje).

     Nukeliaukite į katalogą, kuriame norite atsisiųsti projektą.

          cd /kelias/iki/katalogo

     Nukopijuokite projektą iš GitHub naudodami komandą:

          git clone https://github.com/CoderGuga/2-oji_Uzduotis.git

   Pereikite į projekto katalogą:
   
          cd 2-oji_Uzduotis/v2.0


3. Programos Kompiliavimas


     Sukurkite "build" katalogą ir pereikite į jį:

          mkdir build && cd build

     Paleiskite "CMake" komandą:

          cmake ..

     Kompiliuokite programą:

  Windows (naudojant MinGW):

    mingw32-make

  Linux / macOS:
  
    make



4. Programos Paleidimas

     Po sėkmingo kompiliavimo, galite paleisti programą:

  Windows:

    ./Papildoma.exe

  Linux / macOS:
  
    ./Papildoma
