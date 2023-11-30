#include <stdio.h>
#include <string.h>

void encrypt(const char* key, const char* inputFileName){
  FILE* inputFile, *outputFile;
  inputFile = fopen(inputFileName, "r");

  if(inputFile == NULL){
    printf("Make %s !!!\n", inputFileName);
    return;
  }

  outputFile = fopen("encrypted.txt", "w"); // output File Name

  int keyLength = strlen(key);
  int keyIndex = 0;
  char c;


  while ((c = fgetc(inputFile)) != EOF){

    c = c ^ key[keyIndex];
    keyIndex = (keyIndex + 1) % keyLength;

    fputc(c, outputFile);
  }

  fclose(inputFile);
  fclose(outputFile);
}


void decrypt(const char* key, const char* inputFileName){
  FILE* inputFile, *outputFile;
  inputFile = fopen(inputFileName, "r");

  if(inputFile == NULL){
    printf("Make %s !!!\n", inputFileName);
    return;
  }

  outputFile = fopen("decrypted.txt", "w"); // output File Name

  int keyLength = strlen(key);
  int keyIndex = 0;
  char c;


  while ((c = fgetc(inputFile)) != EOF){

    c = c ^ key[keyIndex];
    keyIndex = (keyIndex + 1) % keyLength;

    fputc(c, outputFile);
  }

  fclose(inputFile);
  fclose(outputFile);
}


int main(){

  int start = 1;
  int value;
  char key[100];
  char inputFileName[] = "input.txt";  // input File Name

  while (start) {
      printf("\n| MENU |\n");
      printf(" 1 -> Encrypt\n");
      printf(" 2 -> Decrypt\n");
      printf(" 0 -> Exit\n\n");

      printf("Enter value : ");
      scanf("%d", &value);

      switch (value) {
          case 1:
              printf(" Key for encrypt = ");
              scanf("%s", key);
              encrypt(key, inputFileName);
              break;
              case 2:
                  printf(" Key for decrypt = ");
                  scanf("%s", key);
                  decrypt(key, inputFileName);
                  break;

              case 0:
                  start = 0;
                  break;

              default:
                  printf("Enter 1, 2, or 0 !!!\n");
                  break;
          }
      }
  return 0;
}
