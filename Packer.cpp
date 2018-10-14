

#include "pch.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Packer.h"
#include "Area.h"



Packer::Packer (short quickReSeed) {

  // random first placement
  int i { 0 };
  int j { 0 };
  //reSeedStorage = quickReSeed;
  srand ((unsigned int)time (NULL) + quickReSeed);
  do {
    i = rand () % (19 - 3) + 3;
    j = rand () % (89 - 3) + 3;
  } while (i % 2 == 0 || j % 2 == 0);
  gotoXY (j, i); ColourCout (u8"☻", 0x0f);
  position.X = j;
  position.Y = i;

  // random direction
  int r { 0 };
  srand ((unsigned int)time (NULL) + quickReSeed);
  r = (rand () % (1111 - 20) + 20);
  if (r % 2 == 0) {
    RchanceL = true;
  }
  else {
    RchanceL = false;
  }
};


//add:
//Packer (//userchoice) :Sign () {};


//static void blinkPacking (const std::list<Packer> input, unsigned char mode) {
//  std::list<packMan> temp { input };
//  //for (int i = 0; i < 1000; i++) {

//    do {
//      //do {} while (protectedSetCursor == true);
//      gotoXY (temp.front ().position.X, temp.front ().position.Y);
//      ColourCout (u8"▪", 0x0f);
//      temp.pop_front ();
//    } while (temp.size () != 0);
//    std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));; // add delays to the countdown
//    temp = input;

//    do {
//      //do {} while (protectedSetCursor == true);
//      gotoXY (temp.front ().position.X, temp.front ().position.Y);
//      ColourCout (u8"☻", 0x0f);
//      temp.pop_front ();
//    } while (temp.size () != 0);
//    std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));;
//    temp = input;
//  //}
//};


// no static here, since it is not allowed
void Packer::blinkPacking (COORD position, unsigned char mode) {
  //▪▫
  //add: if for characters
  //add: state show/save
  short modeToMilliS { 1 };
  switch (mode) {
  case 1:
    modeToMilliS = 500;
    break;
  case 2:
    modeToMilliS = 400;
    break;
  case 3:
    modeToMilliS = 200;
    break;
  case 4:
    modeToMilliS = 1000;
    break;
  }
  //do {} while (protectedSetCursor == true);
  std::this_thread::sleep_for (std::chrono::milliseconds (1000));;
  gotoXY (position.X, position.Y);
  ColourCout (u8"▪", 0x0f);
  std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));;
  //do {} while (protectedSetCursor == true);
  gotoXY (position.X, position.Y);
  ColourCout (u8"☻", 0x0f);
  std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));;
};

void Packer::horizontalMovement (std::list<Packer> input, unsigned char mode) {
  short modeToMilliS { 1 };
  COORD position;
  switch (mode) {
  case 1:
    modeToMilliS = 500;
    break;
  case 2:
    modeToMilliS = 400;
    break;
  case 3:
    modeToMilliS = 200;
    break;
  case 4:
    modeToMilliS = 1000;
    break;
  }
  for (int i = 0; i < 1000; i++) {
    do {
      if (input.front ().RchanceL == true) {
        if (input.front ().position.X != 87) {
          //do {} while (protectedSetCursor == true);
          gotoXY (input.front ().position.X, input.front ().position.Y);
          ColourCout (u8" ", 0x0f);
          input.front ().position.X += 2;
          //do {} while (protectedSetCursor == true);
          gotoXY (input.front ().position.X, input.front ().position.Y);
          ColourCout (u8"☻", 0x0f);
          position.X = input.front ().position.X;
          position.Y = input.front ().position.Y;
          Area::yellow (position);
          Packer::blinkPacking (position, 3);
          input.emplace_back (input.front ());
          input.pop_front ();
          std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));;
          Area::green (position);
        }
        else
          input.front ().RchanceL = false;
      }
      else
        if (input.front ().position.X != 3) {
          //do {} while (protectedSetCursor == true);
          gotoXY (input.front ().position.X, input.front ().position.Y);
          ColourCout (u8" ", 0x0f);
          input.front ().position.X -= 2;
          //do {} while (protectedSetCursor == true);
          gotoXY (input.front ().position.X, input.front ().position.Y);
          ColourCout (u8"☻", 0x0f);
          position.X = input.front ().position.X;
          position.Y = input.front ().position.Y;
          Area::yellow (position);
          Packer::blinkPacking (position, 3);
          input.emplace_back (input.front ());
          input.pop_front ();
          std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));;
          Area::green (position);
        }
        else
          input.front ().RchanceL = true;
      //add: while user decide to involve himself
    } while (input.size () != 0);
  }
};