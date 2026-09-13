#ifndef BUILDEX_H
#define BUILDEX_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char* remhead(char* path, int hl);
extern int FindAllFiles(PCTSTR fpath, char** fout, int ri);

#endif