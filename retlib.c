#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int bof(FILE *badfile)
{
    char buffer[12];
	
	  // vulnerable con buffer overflow attack
    fread(buffer, sizeof(char), 40, badfile);

    return 1;
}

int main(int argc, char **argv)
{
    FILE *badfile;
    badfile = fopen("badfile", "r");
    bof(badfile);

    printf("Returned Properly\n");

    fclose(badfile);
    return 1;
}
