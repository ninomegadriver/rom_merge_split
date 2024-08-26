/* rom_merge 
   A simple console program to merge two ROM files into one single
   binary file.
   Nino MegaDriver <nino@nino.com.br>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char* argv[])
{
    FILE *part1, *part2, *outfile;
    char ch1[1], ch2[1];
    int count=0;
 
    part1 = fopen(argv[1], "rb");
    part2 = fopen(argv[2], "rb");
 
    if (part1 == NULL || part2 == NULL ) {
        printf("Usage: rom_merge [input file1] [input file2] [output file] \n");
        return -1;
    }

    fseek(part1, 0L, SEEK_END); int len1 = ftell(part1); fseek(part1, 0L, SEEK_SET);
    fseek(part2, 0L, SEEK_END); int len2 = ftell(part2); fseek(part2, 0L, SEEK_SET);

    if(len1 != len2){
        printf("File sizes mismatch!\n");
        return -1;
    }

    outfile = fopen(argv[3], "wb");
    if(outfile == NULL){
        printf("Can't write to '%s'!\n", argv[3]);
        return -1;
    }

    printf("Merging '%s' and '%s' into '%s' ...\n", argv[1], argv[2], argv[3]);
    for(int i = 0; i < len1; i++) {
        fread(ch1, 1, 1, part1);
        fwrite(&ch1, 1, sizeof ch1, outfile);
        fread(ch2, 1, 1, part2);
        fwrite(&ch2, 1, sizeof ch2, outfile);
    }
    printf("Done!\n");
    fclose(part1);
    fclose(part2);
    fclose(outfile);
    return 0;
}