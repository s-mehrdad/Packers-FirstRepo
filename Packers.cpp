// Packers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

#include "pch.h"
#include "ConsoleAdjustments.h"

HANDLE consoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
COORD CurrentCursorPosition;
std::stack<bool> stack;


void gotoXY (int x, int y) {
  COORD Position;
  Position.X = x;
  Position.Y = y;
  stack.push (true);
  SetConsoleCursorPosition (consoleHandle, Position);
  stack.pop ();
}



class Area {
  int rows;
  int columns;
  struct materials {
    std::string hWalls { u8"━" };
    std::string vWalls { u8"┃" };
    std::string edges[4] { u8"┏",u8"┗",u8"┛",u8"┓" };
    std::string pack { u8"♣" };
  } stuff;
public:

  Area (unsigned char mode) :rows (19), columns (89) {

    for (int i = 1; i <= 19; i++) {
      for (int j = 1; j <= 89; j++) {
        gotoXY (j, i);

        // first horizontal wall
        if (i == 1 && j != 89) {

          // left top edge
          if (i == 1 && j == 1)
            std::cout << stuff.edges[0];
          std::cout << stuff.hWalls;
        }

        // right top edge
        if (i == 1 && j == 89)
          std::cout << stuff.edges[3];

        // left bottom edge
        if (i == 19 && j == 1)
          std::cout << stuff.edges[1];

        // second horizontal wall
        if (i == 19 && j != 89)
          std::cout << stuff.hWalls;
        else
          // right bottom edge
          if (i == 19 && j == 89)
            std::cout << stuff.edges[2];
          else

            // vertical walls
            if (j == 1 || j == 89)
              if (i != 1)
                std::cout << stuff.vWalls;

        if (mode == 1) {
          // packs
          if (i != 1 && i != 19 && i % 2 == 0)
            if (j != 1 && j != 89 && j % 2 == 0)
              //if (j!=11&&j!=99)
              ColourCout (stuff.pack, 0x0a);
        }
        std::cout << u8"\n";
      }
    }


  };
  //Area(//userchoice) :rows (),columns() {};

  void yellow (COORD position) {
    int i = position.Y;
    int j = position.X;
    if (j - 1 != 2) {
      gotoXY (j - 1, i - 1); ColourCout (u8"♣", 0x06);
      gotoXY (j - 1, i + 1); ColourCout (u8"♣", 0x06);
    }
    if (j + 1 != 88) {
      gotoXY (j + 1, i + 1); ColourCout (u8"♣", 0x06);
      gotoXY (j + 1, i - 1); ColourCout (u8"♣", 0x06);
    }
    if (i - 1 != 2) {
      gotoXY (j - 1, i - 1); ColourCout (u8"♣", 0x06);
      gotoXY (j + 1, i - 1); ColourCout (u8"♣", 0x06);
    }
    if (i + 1 != 18) {
      gotoXY (j - 1, i + 1); ColourCout (u8"♣", 0x06);
      gotoXY (j + 1, i + 1); ColourCout (u8"♣", 0x06);
    }

  }
  void red (COORD position) {
    int i = position.Y;
    int j = position.X;
    if (j - 1 != 2) {
      gotoXY (j - 1, i - 1); ColourCout (u8"♣", 0x04);
      gotoXY (j - 1, i + 1); ColourCout (u8"♣", 0x04);
    }
    if (j + 1 != 88) {
      gotoXY (j + 1, i + 1); ColourCout (u8"♣", 0x04);
      gotoXY (j + 1, i - 1); ColourCout (u8"♣", 0x04);
    }
    if (i - 1 != 2) {
      gotoXY (j - 1, i - 1); ColourCout (u8"♣", 0x04);
      gotoXY (j + 1, i - 1); ColourCout (u8"♣", 0x04);
    }
    if (i + 1 != 18) {
      gotoXY (j - 1, i + 1); ColourCout (u8"♣", 0x04);
      gotoXY (j + 1, i + 1); ColourCout (u8"♣", 0x04);
    }
  }

  void fullPacked () {

  }


};



class packMan {
  char Sign;
public:
  COORD position;

  packMan (int quickReSeed) {
    int i { 0 };
    int j { 0 };
    srand ((unsigned int)time (NULL) + quickReSeed);
    do {
      i = rand () % (19 - 3) + 3;
      j = rand () % (89 - 3) + 3;
    } while (i % 2 == 0 || j % 2 == 0);
    gotoXY (j, i); ColourCout (u8"☻", 0x0f);
    position.X = j;
    position.Y = i;
  };

  static void blinkPacking (const std::list<packMan> input, unsigned char mode) {
    //▪▫
    //add: if for characters
    short modeToMilliS { 0 };
    switch (mode) {
    case 1:
      modeToMilliS = 500;
      break;
    case 2:
      modeToMilliS = 400;
      break;
    case 3:
      modeToMilliS = 300;
      break;
    case 4:
      modeToMilliS = 200;
      break;
    case 5:
      modeToMilliS = 1000;
      break;
    default:
      modeToMilliS = 500;
      break;
    }
    std::list<packMan> temp { input };
    for (int i = 0; i < 100; i++) {

      do {
        gotoXY (temp.front ().position.X, temp.front ().position.Y);
        ColourCout (u8"▪", 0x0f);
        temp.pop_front ();
      } while (temp.size () != 0);
      std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));; // add delays to the countdown
      temp = input;

      do {
        gotoXY (temp.front ().position.X, temp.front ().position.Y);
        ColourCout (u8"☻", 0x0f);
        temp.pop_front ();
      } while (temp.size () != 0);
      std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));;
      temp = input;

    }

  };





  //packMan (//userchoice) :Sign () {};

  //COORD GetPackerCursorPosition (HANDLE hConsoleOutput) {
  //  CONSOLE_SCREEN_BUFFER_INFO consoleScreenBinfo;
  //  if (GetConsoleScreenBufferInfo (hConsoleOutput, &consoleScreenBinfo)) {
  //    return consoleScreenBinfo.dwCursorPosition;
  //  }
  //  else {
  //    // call GetLastError() for detail
  //    COORD invalid {0,0};
  //    return invalid;
  //  }
  //}
};


bool running = true;
int a { 1 }, b { 1 }, c { 1 };
bool flag = false;



void pressed (void) {
  if (GetAsyncKeyState (VK_DOWN)) {
    if (a == 1 && flag == false) {
      gotoXY (74, 25); ColourCout (u8"  ", 0x0c);
      gotoXY (74, 26); ColourCout (u8"->", 0x0c);
      a = 2;
      flag = true;
    }
    if (a == 2 && flag == false) {
      gotoXY (74, 26); ColourCout (u8"  ", 0x0c);
      gotoXY (74, 27); ColourCout (u8"->", 0x0c);
      a = 3;
      flag = true;
      //break;
    }
    flag = false;
  }
  if (GetAsyncKeyState (VK_UP)) {
    if (a == 2 && flag == false) {
      gotoXY (74, 25); ColourCout (u8"->", 0x0c);
      gotoXY (74, 26); ColourCout (u8"  ", 0x0c);
      a = 1;
      flag = true;
    }
    if (a == 3 && flag == false) {
      gotoXY (74, 26); ColourCout (u8"->", 0x0c);
      gotoXY (74, 27); ColourCout (u8"  ", 0x0c);
      a = 2;
      flag = true;
    }
    flag = false;
  }
  if (GetAsyncKeyState (VK_LEFT)) {

  }
  if (GetAsyncKeyState (VK_RIGHT)) {

  }
  if (GetAsyncKeyState (VK_RETURN)) {
    if (a == 1 && flag == false) {
      gotoXY (74, 25); ColourCout (u8"-> Involve me!", 0x04);
    }
  }
}


int main () {
  // font
  COORD fontS { 10,20 };
  ConsoleFont_SizeColour (fontS, L"Consolas", 0x09);
  // screen
  COORD leftANDtop { 15,15 };
  COORD widthANDheight { 107,28 };
  COLORREF backColour { RGB (50,50,50) };
  ConsoleScreen_SizeColourPosition (leftANDtop, widthANDheight, backColour);
  // codec
  UINT consoleOutputCPstorage;
  consoleOutputCPstorage = GetConsoleOutputCP (); // for later use
  SetConsoleOutputCP (CP_UTF8); // https://docs.microsoft.com/de-de/windows/desktop/Intl/code-page-identifiers
  // cursor
  ConsoleCursor_State (false);


  Area area1 (1);


  std::list<packMan> dataset;

  packMan Packer1 (102);
  dataset.insert (dataset.begin (), Packer1);
  packMan Packer2 (323);
  dataset.insert (dataset.begin (), Packer2);

  packMan Packer3 (766);
  dataset.insert (dataset.begin (), Packer3);

  packMan Packer4 (332);
  dataset.insert (dataset.begin (), Packer4);

  packMan Packer5 (373);
  dataset.insert (dataset.begin (), Packer5);

  packMan Packer6 (333);
  dataset.insert (dataset.begin (), Packer6);




  area1.yellow (Packer1.position);
  area1.yellow (Packer2.position);
  area1.yellow (Packer3.position);
  area1.red (Packer4.position);
  area1.red (Packer5.position);
  area1.red (Packer6.position);




  gotoXY (7, 0);
  std::cout << u8"Feel free to way in as a packer toward becoming an advanced packer ♥♥♥♥♥ :)";


  gotoXY (3, 20); ColourCout (u8"Packing speed:", 0x0f);
  gotoXY (3, 21); ColourCout (u8"  Stone age.", 0x0f);
  gotoXY (2, 21); ColourCout (u8"->", 0x0c);
  gotoXY (3, 22); ColourCout (u8"  Middle age...", 0x0f);
  gotoXY (3, 23); ColourCout (u8"  Advanced age.........", 0x0f);
  gotoXY (3, 24); ColourCout (u8"  Hollow age.         .", 0x0f);
  gotoXY (35, 20); ColourCout (u8"Character Choices:", 0x0f);
  gotoXY (35, 21); ColourCout (u8"  ☺  ", 0x07);
  gotoXY (40, 22); ColourCout (u8"    ☻", 0x0f);
  gotoXY (40, 22); ColourCout (u8"->", 0x0c);
  gotoXY (65, 21); ColourCout (u8"  Involve me!", 0x0f);
  gotoXY (64, 21); ColourCout (u8"->", 0x0c);
  gotoXY (65, 22); ColourCout (u8"  Let me furnish! :)", 0x0f);
  gotoXY (65, 23); ColourCout (u8"  Let's hit the road!", 0x0f);



  // guide bar
  int i { 26 };
  for (int j = 1; j <= 89; j++) {
    gotoXY (j, i); ColourCout (u8"-", 0x09);
    i++;
    gotoXY (j, i); ColourCout (u8"-", 0x09);
    i--;
  }




  // status bar





  // coding for action area
  std::thread t1 (packMan::blinkPacking, dataset, 1);







  while (running) {
    system ("pause>nul");


    pressed ();






  }



  t1.join ();
  SetConsoleOutputCP (consoleOutputCPstorage); // important: always set codec back to what it was
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
