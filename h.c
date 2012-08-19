#include <stdio.h>
#include <string.h>

static char small_h = 'h';
static char big_h   = 'H';
static char *usage = "usage: ./h [-f <file> | -h | -H]\n";

int open_h_file(char *input[]){
  FILE *h_file;
  if(!(h_file = fopen(input[2], "a+"))){
    perror("fopen");
    return 1;
  }  
  fprintf(h_file, "h\n");
  fclose(h_file);
  return 0;
}

int main(int argc, char *argv[]) {      
  if(argc < 2){
    fprintf(stderr, "%s", usage);
    return 1;
  }
  if(argc >= 2){
    if(strcmp(argv[1], "-f") == 0)
      open_h_file(argv);
    if(strcmp(argv[1], "-H") == 0)
      fprintf(stdout, "%c\n", big_h);
    if(strcmp(argv[1], "-h") == 0)
      fprintf(stdout, "%c\n", small_h);
  }
  return 0;
}