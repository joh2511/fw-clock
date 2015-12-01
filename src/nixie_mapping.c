#include "platform_config.h"

#ifdef CFG_TYPE_NIXIE
#include "nixie.h"

/*
EUROGRID - Shiftregister layout

(  Tube6  )(  Tube5  )  (  Tube4  ) (  Tube3  )  (  Tube2  )(  Tube1  ) <- Tubes
67098123 45670981 2345**67 09812345 67098123 45**6709 81234567 09812345 <- Tube digits
|||||||| |||||||| |||||||| |||||||| |||||||| |||||||| |||||||| ||||||||
HGFEDCBA HGFEDCBA HGFEDCBA HGFEDCBA HGFEDCBA HGFEDCBA HGFEDCBA HGFEDCBA <- Shiftregister Outputs
 Reg. 8   Reg. 7   Reg. 6   Reg. 5   Reg. 4   Reg. 3   Reg. 2   Reg. 1  <- Shiftregisters

The mapping of the tube pins is repeating in 10bit periods.
Therefore it is possible to use following constants to select the digits to display:

  |     Nixie-tube    |
  \___________________/
   | | | | | | | | | |
   6 7 0 9 8 1 2 3 4 5

0b 0 0 1 0 0 0 0 0 0 0  0x0080  <- Displays 0
0b 0 0 0 0 0 1 0 0 0 0  0x0010  <- Displays 1
0b 0 0 0 0 0 0 1 0 0 0  0x0008  <- Displays 2
0b 0 0 0 0 0 0 0 1 0 0  0x0004  <- Displays 3
0b 0 0 0 0 0 0 0 0 1 0  0x0002  <- Displays 4
0b 0 0 0 0 0 0 0 0 0 1  0x0001  <- Displays 5
0b 1 0 0 0 0 0 0 0 0 0  0x0200  <- Displays 6
0b 0 1 0 0 0 0 0 0 0 0  0x0100  <- Displays 7
0b 0 0 0 0 1 0 0 0 0 0  0x0020  <- Displays 8
0b 0 0 0 1 0 0 0 0 0 0  0x0040  <- Displays 9

The bitwurst is shifted from right to left in the shiftregisters shown above.
After every two tubes are two dots to seperate the seconds, minutes and hours.
*/

/*
B13D - Shiftregister layout

(  Tube6  )(  Tube5  )  (  Tube4  ) (  Tube3  )  (  Tube2  )(  Tube1  ) <- Tubes
12345678 90123456 7890**12 34567890 12345678 90**1234 56789012 34567890 <- Tube digits
|||||||| |||||||| |||||||| |||||||| |||||||| |||||||| |||||||| ||||||||
HGFEDCBA HGFEDCBA HGFEDCBA HGFEDCBA HGFEDCBA HGFEDCBA HGFEDCBA HGFEDCBA <- Shiftregister Outputs
 Reg. 8   Reg. 7   Reg. 6   Reg. 5   Reg. 4   Reg. 3   Reg. 2   Reg. 1  <- Shiftregisters

The mapping of the tube pins is repeating in 10bit periods.
Therefore it is possible to use following constants to select the digits to display:

  |     Nixie-tube    |
  \___________________/
   | | | | | | | | | |
   1 2 3 4 5 6 7 8 9 0

0b 0 0 0 0 0 0 0 0 0 1  0x0001  <- Displays 0
0b 1 0 0 0 0 0 0 0 0 0  0x0200  <- Displays 1
0b 0 1 0 0 0 0 0 0 0 0  0x0100  <- Displays 2
0b 0 0 1 0 0 0 0 0 0 0  0x0080  <- Displays 3
0b 0 0 0 1 0 0 0 0 0 0  0x0040  <- Displays 4
0b 0 0 0 0 1 0 0 0 0 0  0x0020  <- Displays 5
0b 0 0 0 0 0 1 0 0 0 0  0x0010  <- Displays 6
0b 0 0 0 0 0 0 1 0 0 0  0x0008  <- Displays 7
0b 0 0 0 0 0 0 0 1 0 0  0x0004  <- Displays 8
0b 0 0 0 0 0 0 0 0 1 0  0x0002  <- Displays 9

The bitwurst is shifted from right to left in the shiftregisters shown above.
After every two tubes are two dots to seperate the seconds, minutes and hours.
*/

const uint16_t digitMap[NIXIE_MAP_END][10] =
{
    { 0x0080, 0x0010, 0x0008, 0x0004, 0x0002, 0x0001, 0x0200, 0x0100, 0x0020, 0x0040 },
    { 0x0001, 0x0200, 0x0100, 0x0080, 0x0040, 0x0020, 0x0010, 0x0008, 0x0004, 0x0002 }
};

#endif // CFG_TYPE_NIXIE