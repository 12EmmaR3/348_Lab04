#include <stdio.h>
int main(){
  int running = 1;
  int score;
  while(running == 1){ //infinite loop
    printf("Enter 0 or 1 to STOP\nEnter the NFL score:");
    scanf("%d",&score); //stores the given score
    if(score <= 1){
      printf("Exiting the program..\n");
      running = 0;  //gets out of the infinite loop
    }else{
      printf("\nPossible combinations of scoring plays for a score of %d:\n", score);
      for (int TD2 = 0; TD2 <= score / 8; TD2++) {  //checks for all possibilities with touchdown+2points
        for (int TD1 = 0; TD1 <= score / 7; TD1++) {   //checks for all possibilities with touchdown+1points
          for (int TD = 0; TD <= score / 6; TD++) { //checks for all possibilities with touchdown
            for (int FG = 0; FG <= score / 3; FG++) {   //checks for all possibilities with field goals
              for (int safety = 0; safety <= score / 2; safety++) {  //checks for all possibilities with saftey
                int total = (TD2 * 8) + (TD1 * 7) + (TD * 6) + (FG * 3) + (safety * 2); //adds the number of each possibility today
                if (total == score) {
                  printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD2, TD1, TD, FG, safety); //prints out all the statements
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