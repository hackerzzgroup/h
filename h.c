#include <stdio.h>
#include <string.h>

static char small_h = 'h';
static char big_h   = 'H';
static char *usage = "usage: ./h [-f <file> | -h | -H]\n";

int open_h_file(char *path){
  FILE *h_file;
  if(!(h_file = fopen(path, "a+"))){
    perror("fopen");
    return 1;
  }  
  fprintf(h_file, "h\n");
  fclose(h_file);
  return 0;
}

int main(int argc, char *argv[]) {
  if(argc == 3 && !strcmp(argv[1], "-f")){
    open_h_file(argv[2]);
  } else if(argc == 2 && !strcmp(argv[1], "-H")) {
    fprintf(stdout, "%c\n", big_h);
  } else if(argc == 2 && !strcmp(argv[1], "-h")) {
    fprintf(stdout, "%c\n", small_h);
  } else {
    fprintf(stderr, "%s", usage);
    return 1;
  }
  return 0;
}