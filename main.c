#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

void printpermissions(mode_t mode){
  char permissions[10] = "rwxrwxrwx";
  for(int i = 0; i < 9; i++){
    if(!(mode & 1<<(8-i))){
      printf("-");
    }else{
      printf("%c", permissions[i]);
    }
  }
  printf("\n");
}

int main(){
  struct stat test;

  stat("main.c", &test);
  printf("file size: %lld\n", test.st_size);
  printf("mode: %o\n", test.st_mode);
  printf("accessed: %s\n", ctime(&test.st_atime));

  char buffer[100];
  sprintf(buffer, "%lld B\t%lld KB\t%lld MB\t%lld GB", test.st_size, test.st_size/1000, test.st_size/1000000, test.st_size/1000000000);

  printf("%s\n", buffer);

  printpermissions(test.st_mode);
}
