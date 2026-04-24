#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>

long sizeof_fn(char *file);

// Takes a file path as an argument and returns the size of the file in bytes
// and kilobytes
int main(int argc, char *argv[]) {
  if (argc > 2) {
    printf("Got more then 1 arguments");
    exit(1);
  }

  long file_size = sizeof_fn(argv[1]);

  printf("Size: \n%ld Bytes\n%ld KBytes\n", file_size, file_size / 1024);
}

long sizeof_fn(char *file) {
  FILE *fptr;
  fptr = fopen(file, "r");

  fseek(fptr, 0, SEEK_END);

  return ftell(fptr);
}
