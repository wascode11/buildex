#include "buildex.h"

int main() {
    const char* path = ".";
    char* fout[100];
    FindAllFiles(path, fout, 0);
    for (int i = 0; i < 100 && fout[i] != NULL; i++) {
        char* target = remhead(fout[i], 2);
        char* cmd = (char*)malloc(100);
        snprintf(cmd, 100, "cl /c /EHsc /Fo:build\\ %s", target);
        printf("Compiling: %s\n", cmd);
        system(cmd);
        free(cmd);
    }
    system("link /OUT:build\\buildex.exe build\\*.obj");
    return 0;
}