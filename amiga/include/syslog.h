/* Berusky for AmigaOS: libnix has no syslog; src/utils.h only logs "Out of
 * memory!" with it before it stops. The AmiCradle Team. GPL 2 or later. */
#ifndef AMIGA_SYSLOG_H
#define AMIGA_SYSLOG_H
#define syslog(pri, ...) ((void)0)
#endif
