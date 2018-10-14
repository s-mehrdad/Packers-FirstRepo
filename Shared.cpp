

#include "pch.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"





void loading (void) {
  //for (int j = 1; j <= 89; j++) {
  //  gotoXY (j, i); ColourCout (u8"-", 0x09);
  //  i++;
  //  gotoXY (j, i); ColourCout (u8"-", 0x09);
  //  i--;
  //}
  int i { 19 };
  for (int j = 40; j <= 54; j++) {
    gotoXY (j, i); ColourCout (u8" ", 0x3f);
    std::this_thread::sleep_for (std::chrono::milliseconds (50));;
  }
  gotoXY (44, i); ColourCout (u8"L", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));;
  gotoXY (45, i); ColourCout (u8"O", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));;
  gotoXY (46, i); ColourCout (u8"A", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));;
  gotoXY (47, i); ColourCout (u8"D", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));;
  gotoXY (48, i); ColourCout (u8"I", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));;
  gotoXY (49, i); ColourCout (u8"N", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (60));;
  gotoXY (50, i); ColourCout (u8"G", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (500));;
  gotoXY (48, i); ColourCout (u8" ", 0x3f);
  gotoXY (49, i); ColourCout (u8" ", 0x3f);
  gotoXY (50, i); ColourCout (u8" ", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (100));;
  gotoXY (54, i); ColourCout (u8"━", 0x09);
  gotoXY (48, i); ColourCout (u8"E", 0x3f);
  gotoXY (49, i); ColourCout (u8"D", 0x3f);
  std::this_thread::sleep_for (std::chrono::milliseconds (500));;
  for (int j = 53; j >= 40; j--) {
    gotoXY (j, i); ColourCout (u8"━", 0x09);
    std::this_thread::sleep_for (std::chrono::milliseconds (50));;
  }
}


void pressed (unsigned char menu[], bool flag) {
  if (GetAsyncKeyState (VK_DOWN)) {
    if (menu[0] == 1 && flag == false) {
      //do {} while (protectedSetCursor == true);
      gotoXY (64, 21); ColourCout (u8"  ", 0x0c);
      //do {} while (protectedSetCursor == true);
      gotoXY (64, 22); ColourCout (u8"->", 0x0c);
      menu[0] = 2;
      flag = true;
    }
    if (menu[0] == 2 && flag == false) {
      //do {} while (protectedSetCursor == true);
      gotoXY (64, 22); ColourCout (u8"  ", 0x0c);
      //do {} while (protectedSetCursor == true);
      gotoXY (64, 23); ColourCout (u8"->", 0x0c);
      menu[0] = 3;
      flag = true;
      //break;
    }
    flag = false;
  }
  if (GetAsyncKeyState (VK_UP)) {
    if (menu[0] == 2 && flag == false) {
      //do {} while (protectedSetCursor == true);
      gotoXY (64, 21); ColourCout (u8"->", 0x0c);
      //do {} while (protectedSetCursor == true);
      gotoXY (64, 22); ColourCout (u8"  ", 0x0c);
      menu[0] = 1;
      flag = true;
    }
    if (menu[0] == 3 && flag == false) {
      //do {} while (protectedSetCursor == true);
      gotoXY (64, 22); ColourCout (u8"->", 0x0c);
      //do {} while (protectedSetCursor == true);
      gotoXY (64, 23); ColourCout (u8"  ", 0x0c);
      menu[0] = 2;
      flag = true;
    }
    flag = false;
  }
  if (GetAsyncKeyState (VK_LEFT)) {

  }
  if (GetAsyncKeyState (VK_RIGHT)) {

  }
  if (GetAsyncKeyState (VK_RETURN)) {
    if (menu[0] == 1 && flag == false) {
      //do {} while (protectedSetCursor == true);
      gotoXY (64, 21); ColourCout (u8"-> Involve me!", 0x04);
    }
  }
}