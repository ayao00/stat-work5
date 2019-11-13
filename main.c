#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
  struct stat test;

  stat("main.c", &test);
  printf("file size: %lld\n", test.st_size);
  printf("mode: %o\n", test.st_mode);
  printf("%s\n", ctime(&test.st_atime));

  char buffer[100];
  sprintf(buffer, "%d B\t%d KB\t%d MB\t%d GB", test.st_size, test.st_size);
}
