/* Berusky for AmigaOS (from the Critical Mass, TecnoballZ and Biniax-2
 * ports): the part of SDL_image 1.2 the game uses, made by
 * amiga/sdl_image_lite.c, since OpenGPU's SDL 1.2 kit has no
 * SDL_image 1.2. The AmiCradle Team. GPL 2 or later, like Berusky. */
#ifndef AMIGA_SDL_IMAGE_LITE_H
#define AMIGA_SDL_IMAGE_LITE_H
#include <SDL.h>
#ifdef __cplusplus
extern "C" {
#endif
SDL_Surface *IMG_Load(const char *file);
SDL_Surface *IMG_LoadPNG_RW(SDL_RWops *src);
int IMG_InvertAlpha(int on);
const SDL_version *IMG_Linked_Version(void);
#define IMG_GetError SDL_GetError
#define IMG_SetError SDL_SetError
#ifdef __cplusplus
}
#endif
#endif
