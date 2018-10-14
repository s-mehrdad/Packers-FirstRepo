#pragma once

#ifndef PACKER_H
#define PACKER_H



class Packer {
  char Sign;
public:
  bool RchanceL;
  COORD position;
  Packer (short);
  static void blinkPacking (COORD, unsigned char);
  static void horizontalMovement (std::list<Packer>, unsigned char);
};



#endif // !PACKER_H
