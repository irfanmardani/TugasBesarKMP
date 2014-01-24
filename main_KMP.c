#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



int  carikmp(char *string, char *kata, int *ptr,bool *ketemu) {
      int i = 0, j = 0;
      while ((i + j) < strlen(string)) {
              if (kata[j] == string[i + j]) {
                      if (j == (strlen(kata) - 1)) {
                              printf("%s Berada pada indeks ke : %d\n",kata, i);
                              *ketemu=true;
                              return;
                      }
                      j = j + 1;
              } else {
                      i = i + j - ptr[j];
                      if (ptr[j] > -1) {
                              j = ptr[j];
                      } else {
                              j = 0;
                      }
              }
      }
}
/* Mencari kecocokan pada kata dengan pattern */
void carikesamaan(char *kata, int *ptr) {
      int i = 2, j = 0, len = strlen(kata);
      ptr[0] = -1;
      ptr[1] = 0;
      while (i < len) {
              if (kata[i - 1] == kata[j]) {
                      j = j + 1;
                      ptr[i] = j;
                      i = i + 1;
              } else if (j > 0) {
                      j = ptr[j];
              } else {
                      ptr[i] = 0;
                      i = i + 1;
              }
      }
      return;
}

int main() {
      bool ketemu=false;
      char kata[256], string[1024];;
      int *ptr, i;
      
      printf("String Matching Dengan Algoritma KMP\n");
      printf("--------------------------------------------\n");
      /* Inputan teks */
      printf("Masukan Teks:");
      fgets(string, 1024, stdin);
      string[strlen(string) - 1] = '\0';

      /* Inputan Pattern*/
      printf("Masukan Pattern:");
      fgets(kata, 256, stdin);
      kata[strlen(kata) - 1] = '\0';

      /* Array pinggiran */
      ptr = (int *)calloc(1, sizeof(int) * (strlen(kata)));

      /* Mencari kesamaan kata dengan pattern */
      carikesamaan(kata, ptr);
      /* mencari indeks pattern pada teks */
      carikmp(string, kata, ptr,&ketemu);
      if(ketemu==false){
         printf("\nTidak ditemukan");
      }
      getch();
      return 0;
}
