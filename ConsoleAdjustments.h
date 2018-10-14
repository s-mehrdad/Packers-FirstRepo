#pragma once


void ConsoleFont_SizeColour (COORD, LPCWSTR, WORD);
void ConsoleScreen_SizeColourPosition (COORD, COORD, COLORREF);
void ConsoleCursor_State (bool);
void ColourCout (std::string, WORD);
void gotoXY (int, int);