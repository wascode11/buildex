#include <windows.h>
#include <stdio.h>
#include <string.h>

int FindAllFiles(PCTSTR fpath, char** fout, int ri) { // fxxx = function/full xxx
    WIN32_FIND_DATA findFileData;

    char path[MAX_PATH];

    char searchPath[MAX_PATH];

    int i = ri;

    snprintf(path, sizeof(path), "%s", fpath);

    snprintf(searchPath, sizeof(searchPath), "%s\\*", path);

    HANDLE hFind = FindFirstFile(searchPath, &findFileData);

    do {
        if (strcmp(findFileData.cFileName, ".") == 0 || strcmp(findFileData.cFileName, "..") == 0 || strcmp(findFileData.cFileName, ".git") == 0) {
            continue;
        }

        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            printf("<Directory>: %s\\%s\n", path, findFileData.cFileName);
            snprintf(path, sizeof(path), "%s\\%s", path, findFileData.cFileName);
            FindAllFiles(path, fout, i);
            snprintf(path, sizeof(path), "%s", fpath);
        } else {
            printf("<File>: %s\\%s\n", fpath, findFileData.cFileName);
            fout[i] = (char*)malloc(strlen(fpath) + strlen(findFileData.cFileName) + 2);
            snprintf(fout[i], strlen(fpath) + strlen(findFileData.cFileName) + 2, "%s\\%s", fpath, findFileData.cFileName);
            i++;
        }
    } while (FindNextFile(hFind, &findFileData));

    return 0;
}