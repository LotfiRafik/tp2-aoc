//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//
unsigned randxy(unsigned x, unsigned y)
{
  return (x + (rand() % y)) % y; 
}

//
int main(int argc, char **argv)
{
  //
  srand(getpid());
  
  //
  if (argc < 2)
    return printf("Usage: %s [output file] [length]\n", argv[0]), 1;

  //
  unsigned long long len = atoll(argv[2]);
  
  //
  const char bases[4] = "ATCG"; 
  
  //
  FILE *fp = fopen(argv[1], "wb");

  if (!fp)
    return printf("Error: cannot create file '%s'\n", argv[2]), 2;

  if(len%4) 
      return printf("Length of sequence must be multiple of 4\n");

  unsigned char base = 0;
  //Generate random DNA sequence
  for (unsigned long long i = 0; i < len; i++){
    // Generate random number between [0,3] 
    unsigned int r = randxy(0, 4);
    // shift left and apply binary OR to base 
    // this is done in order to concatenate previous base to current base
    /* Example:
      0000 0001 (T)
      0000 0011 (G)
      0000 0000 (A)
      0000 0011 (G)

      After applying shift and OR ==>  0111 0011 (TGAG)
    */

    base = (((unsigned char) r) << (3 - (i%4))*2) | base;
    // Each 4 bases (2bits*4) we print out
    if(i%4==3){
      fprintf(fp, "%c", base);
      // Reinitialise base to 0
      base = 0;
    }
  }

  //
  fclose(fp);
    
  //
  return 0;
}
