Berusky 1.7.2 for AmigaOS 3.x
=============================

Berusky (AnakreoN, https://www.anakreon.cz), the logic game: guide five
beetles through mazes, push boxes, blow walls up with bombs, open doors
with the keys and collect five keys to open the exit. Over 200 levels in
five sets (training to impossible), with a hint for each, and a level
editor. For AmigaOS 3.x on a 68040 or 68060 with an FPU and an RTG
screen, on OpenGPU's SDL 1.2 (sdl12-compat).

Base: berusky_1.7.2.orig.tar.xz from Debian (sha256
0006e5fdaf81260f67258dd65a18a4b2c30243ff89ff3d60f78bc597f9f3ce29), with
Debian's patches (1.7.2-4) as the second commit. Branch
team2/berusky-amiga.

Status: plays in the lab (Instance-45 on GFOpenUp 0.8.19, 6 November
2026): the menu, Play, Training, the level map, level 1 (the beetle moved
with the cursor keys, the step counter), Escape and the game menu, Save
Game, and Quit back to the Shell; user/.berusky has the profile. The game
has no music or sounds.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- GFOpenUp 0.8.18 or later (LIBS:OpenGPU/SDL2.module). Everything else is
  in the program.


How to play
-----------

Open the Berusky icon, or run Berusky from a Shell. It opens a 640x480
window; Settings has full screen and "High resolution mode" (1280x960,
heavy on a 68k). The mouse or the cursor keys and Return choose in the
menus. In a level the cursor keys move the beetle, Tab switches to the
next beetle, F1 is the help, Ctrl+F1 the level's hint, F2 and F3 save and
load, Ctrl+R restarts, Escape is the game menu and Ctrl+X quits.
ReadMe-upstream in the drawer is upstream's ReadMe. Berusky -e starts the
level editor (1024x768). The levels, game data and pictures are in the
drawer; berusky.ini holds the settings, and the profiles and your own
levels are kept in user/.berusky.


Building
--------

    make -f amiga/Makefile.amigaos -j2 dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenNDK headers, the OpenGPU kit and
the Team's static libpng and zlib (see the Makefile's head). The drawer is
dist/Berusky (and dist/Berusky.info).


What was changed
----------------

- src/main.cpp, src/berusky.h: no GTK (upstream only parses its arguments
  with it) and no gettext (English); main() first moves into the drawer
  (amiga/amiga_start.c), where berusky.ini is found.
- src/defines.h, amiga/berusky.ini: the settings are the drawer's
  berusky.ini, with the data at PROGDIR:Levels, PROGDIR:GameData and
  PROGDIR:Graphics and the editor's scratch level in T:; the game starts
  at 640x480 without asking. src/utils.cpp leaves those names as they are
  (upstream turns them into full ones with chdir() and getcwd()).
  $HOME is the drawer's user/ (amiga/amiga_env.c, -Wl,--wrap=getenv).
- amiga/amiga_paths.c (-Wl,--wrap=fopen, open, opendir, stat, mkdir and
  chdir, from the Heroes port): Berusky joins a directory and a name with
  "/", and to AmigaDOS "//" and ":/" are the parent drawer; they are
  folded.
- src/utils.h: on an error the SDL window is closed before exit(), or the
  program hangs. src/berusky_gui.cpp, src/editor.cpp: the editor and the
  editor's "run level" are started as commands and waited for (no
  fork()). src/portability.h: random() is rand(). amiga/include: syslog.h,
  endian.h and error.h, which libnix lacks.
- No SDL_image 1.2 for OpenGPU's SDL 1.2: the Team's amiga/sdl_image_lite.c
  (PNG on libpng; the game's pictures are RGB and RGBA, some 16 bits a
  channel), from the Critical Mass port.
- amiga/stack.c: 256 KB of stack.


Licences
--------

Berusky, its levels, pictures and data: GPL 2 or later (COPYING.txt;
the upstream tarball has no licence file, so the GPL 2 text is
amiga/COPYING.GPL-2; data/*/COPYING give the terms). The Amiga files
(amiga/): the AmiCradle Team, GPL 2 or later; the icons are our
own GlowIcons (amiga/icons/art/berusky.svg).
