#include <stdio.h>
float celsius_to_fahrenheit (float celsius){
  return ((9.0/5.0) *(celsius))+ 32.0;  //conversion formula
}

float celsius_to_kelvin (float celsius){
  return (celsius + 273.15); //conversion formula
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * (5.0 / 9.0); //conversion formula
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return ((fahrenheit - 32.0) * 5.0 / 9.0 + 273.15); //conversion formula
}

float kelvin_to_celsius (float kelvin){
  return (kelvin - 273.15); //conversion formula
}

float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0; //conversion formula
}

void categorize_temperature(float celsius){ //categorizes weather based on how cold/hot it is
  if(celsius < 0){
    printf("Temprature category: Freezing\nWeather advisory: Too cold, stay indoors\n");
  }else if(celsius >= 0 && celsius < 10 ){
    printf("Temprature category: Cold\nWeather advisory: Wear a jacket\n");
  }else if(celsius >= 10 && celsius < 25){
    printf("Temprature category: Comfortable\nWeather advisory: You should feel comfortable\n");
  }else if(celsius >= 25 && celsius < 35){
    printf("Temprature category: Hot\nWeather advisory: Wear sunscreen\n");
  }else{
     printf("Temprature category: Extreme Heat\nWeather advisory: Too hot, stay indoors\n");
  }
}

int main(){
  float temp;
  int cur_choice;
  int converter;
  while (1) { // Outer loop for looping through everything
    int num = 0;
    printf("\nEnter the temperature: ");
    while (scanf("%f", &temp) != 1) { //checks if the scanf returns 0 or 1, if its 0 the input is invalid 
      printf("Invalid input. Please enter a valid temperature: ");
      while (getchar() != '\n'); // clear input buffer
        }

  printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
   while (1) {
    scanf("%d", &cur_choice);
    if (cur_choice >= 1 && cur_choice <= 3) {
      break; // Valid input so the loops finishes 
    }
    printf("You entered an invalid option.\nPlease enter a number between 1 and 3: ");
}
   if(cur_choice == 3 && temp < 0){
    printf("You can not input negative Kelvin\n");   //there can not be negative kelvin
    continue;
    }

  printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    while (1) {
      scanf("%d", &converter);
      if (converter >= 1 && converter <= 3) {
        break; // Valid input, exit loop
      }
      printf("You entered an invalid option.\nPlease enter a number between 1 and 3: ");
    }
  if(cur_choice == 1){ //converts from celsius to another unit
    if(converter == 1){
      printf("Invalid conversion choice\n");
      num = 1;
    }else if(converter == 2){
      printf("Temperature in Farenheit: %.2f °F\n",celsius_to_fahrenheit(temp));
    }else if(converter == 3){
      printf("Temperature in Kelvin: %.2f K\n", celsius_to_kelvin (temp));
    }

  }else if(cur_choice == 2){ //converts from farenheit to another unit
      if(converter == 1){
         printf("Temperature in Celsius: %.2f °C\n", fahrenheit_to_celsius(temp));
      }else if(converter == 2){
         printf("Invalid conversion choice\n");
         num = 1;
      }else if (converter == 3){
        printf("Temperature in Kelvin: %.2f K\n", fahrenheit_to_kelvin(temp));
      }

  }else if(cur_choice == 3){  //converts from kelvin to another unit
    if(converter == 1){
       printf("Temperature in Celsius: %.2f °C\n", kelvin_to_celsius(temp));  
    }else if (converter == 2){
      printf("Temperature in Farenheit: %.2f °F\n",kelvin_to_fahrenheit(temp));
    }else if(converter == 3){
       printf("Invalid conversion choice\n");
       num = 1;
    }

  } if(num != 1){
      if (cur_choice == 1) {
          categorize_temperature(temp); 
      } else if (cur_choice == 2) {
          categorize_temperature(fahrenheit_to_celsius(temp)); //converts to celsius then passes it to the category function
      } else if (cur_choice == 3) {
          categorize_temperature(kelvin_to_celsius(temp)); //converts to celsius then passes it to the category function
      }
  }
    
    char choice;
      printf("Do you want to try again? (y/n): ");
      while (getchar() != '\n');  //continues until it hits a newline
      choice = getchar();
      if (choice != 'y' && choice != 'Y'){
        printf("Bye!\n");
        return 0; // exit the loop if the user doesn't say yes
      }
  }
return 0;
}



