

#include "pch.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"
#include "Packer.h"


struct Area::materials {
  std::string hWalls { u8"━" };
  std::string vWalls { u8"┃" };
  std::string edges[4] { u8"┏",u8"┗",u8"┛",u8"┓" };
  std::string pack { u8"♣" };
} stuff;


Area::Area (unsigned char mode) :rows (19), columns (89) {

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

void Area::green (COORD position) {
  int i = position.Y;
  int j = position.X;
  if (j - 1 != 2) {
    //do {} while (protectedSetCursor == true);
    gotoXY (j - 1, i - 1); ColourCout (u8"♣", 0x02);
    //do {} while (protectedSetCursor == true);
    gotoXY (j - 1, i + 1); ColourCout (u8"♣", 0x02);
  }
  if (j + 1 != 88) {
    //do {} while (protectedSetCursor == true);
    gotoXY (j + 1, i + 1); ColourCout (u8"♣", 0x02);
    //do {} while (protectedSetCursor == true);
    gotoXY (j + 1, i - 1); ColourCout (u8"♣", 0x02);
  }
  if (i - 1 != 2) {
    //do {} while (protectedSetCursor == true);
    gotoXY (j - 1, i - 1); ColourCout (u8"♣", 0x02);
    //do {} while (protectedSetCursor == true);
    gotoXY (j + 1, i - 1); ColourCout (u8"♣", 0x02);
  }
  if (i + 1 != 18) {
    //do {} while (protectedSetCursor == true);
    gotoXY (j - 1, i + 1); ColourCout (u8"♣", 0x02);
    //do {} while (protectedSetCursor == true);
    gotoXY (j + 1, i + 1); ColourCout (u8"♣", 0x02);
  }

}
void Area::yellow (COORD position) {
  int i = position.Y;
  int j = position.X;
  if (j - 1 != 2) {
    //do {} while (protectedSetCursor == true);
    gotoXY (j - 1, i - 1); ColourCout (u8"♣", 0x06);
    //do {} while (protectedSetCursor == true);
    gotoXY (j - 1, i + 1); ColourCout (u8"♣", 0x06);
  }
  if (j + 1 != 88) {
    //do {} while (protectedSetCursor == true);
    gotoXY (j + 1, i + 1); ColourCout (u8"♣", 0x06);
    //do {} while (protectedSetCursor == true);
    gotoXY (j + 1, i - 1); ColourCout (u8"♣", 0x06);
  }
  if (i - 1 != 2) {
    //do {} while (protectedSetCursor == true);
    gotoXY (j - 1, i - 1); ColourCout (u8"♣", 0x06);
    //do {} while (protectedSetCursor == true);
    gotoXY (j + 1, i - 1); ColourCout (u8"♣", 0x06);
  }
  if (i + 1 != 18) {
    //do {} while (protectedSetCursor == true);
    gotoXY (j - 1, i + 1); ColourCout (u8"♣", 0x06);
    //do {} while (protectedSetCursor == true);
    gotoXY (j + 1, i + 1); ColourCout (u8"♣", 0x06);
  }

}
void Area::red (COORD position) {
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

void Area::fullPacked () {

}


