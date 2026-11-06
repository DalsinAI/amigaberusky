/* getenv() for Berusky on AmigaOS (-Wl,--wrap=getenv), from the Team's GNU
 * Robbo and Heroes ports. Berusky keeps its profiles, own levels and
 * settings in ~/.berusky; here $HOME is the drawer's user/ (made at the
 * first start). Every other name is libnix's getenv's.
 * The AmiCradle Team. GPL 2 or later, like Berusky. */
#include <string.h>
#include <sys/stat.h>

char *__real_getenv(const char *name);

char *__wrap_getenv(const char *name)
{
	static int made;
	if (name && strcmp(name, "HOME") == 0) {
		if (!made) {
			mkdir("PROGDIR:user", 0755);
			made = 1;
		}
		return "PROGDIR:user";
	}
	return __real_getenv(name);
}
