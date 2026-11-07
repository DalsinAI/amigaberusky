/* Berusky for AmigaOS: <endian.h> as glibc's, for src/level_game.cpp's
 * byte swap of the levels (the 68k is big-endian). The AmiCradle Team.
 * GPL 2 or later. */
#ifndef AMIGA_ENDIAN_H
#define AMIGA_ENDIAN_H
#define LITTLE_ENDIAN 1234
#define BIG_ENDIAN    4321
#define BYTE_ORDER    BIG_ENDIAN
#endif
