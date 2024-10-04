#include <stdio.h>
int main(){
  int running = 1;
  int score;
  while(running == 1){
    printf("Enter 0 or 1 to STOP\nEnter the NFL score:");
    scanf("%d",&score);
    if(score <= 1){
      printf("Exiting the program..\n");
      running = 0;
    }else{
      printf("\nPossible combinations of scoring plays for a score of %d:\n", score);
      for (int TD2 = 0; TD2 <= score / 8; TD2++) {  
        for (int TD1 = 0; TD1 <= score / 7; TD1++) {  
          for (int TD = 0; TD <= score / 6; TD++) {
            for (int FG = 0; FG <= score / 3; FG++) {  
              for (int safety = 0; safety <= score / 2; safety++) {  
                int total = (TD2 * 8) + (TD1 * 7) + (TD * 6) + (FG * 3) + (safety * 2);
                if (total == score) {
                  printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD2, TD1, TD, FG, safety);
              }
            }
          }
        }
      }
    }
   }
  } 
  return 0;
}