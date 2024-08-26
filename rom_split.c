/* rom_split 
   A simple console program to split one binary file into two
   Nino MegaDriver <nino@nino.com.br>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char* argv[])
{
    FILE *part1, *part2, *inputfile;
    char ch[1]; 
 
    if (argc < 3) {
        printf("Usage: rom_merge [input file]\n");
        return -1;
    }

    inputfile = fopen(argv[1], "rb");
    if(inputfile == NULL){
        printf("Unable to read '%s'\n", argv[2]);
        return -1;
    }

    part1 = fopen(argv[2], "wb");
    if(part1 == NULL){
        printf("Can't write to '%s'\n", argv[2]);
        return -1;
    }

    part2 = fopen(argv[3], "wb");
    if(part2 == NULL){
        printf("Can't write to '%s'\n", argv[3]);
        return -1;
    }

    fseek(inputfile, 0L, SEEK_END); int len = ftell(inputfile); rewind(inputfile);

    printf("Splitting '%s' to '%s' and '%s' ...\n", argv[1], argv[2], argv[3]);
    for(int i = 0; i < len; i++) {
        fread(ch, 1, 1, inputfile);
        if(ftell(part1) < len/2) fwrite(&ch, 1, sizeof ch, part1);
        fread(ch, 1, 1, inputfile);
        if(ftell(part2) < len/2) fwrite(&ch, 1, sizeof ch, part2);
    }

    printf("Done!\n");
    fclose(part1);
    fclose(part2);
    fclose(inputfile);
    return 0;
}