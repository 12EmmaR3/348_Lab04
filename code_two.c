#include <stdio.h>
float celsius_to_fahrenheit (float celsius){
  return ((9.0/5.0) *(celsius))+ 32.0;
}

float celsius_to_kelvin (float celsius){
  return (celsius + 273.15);
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * (5.0 / 9.0);
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return ((fahrenheit - 32.0) * 5.0 / 9.0 + 273.15);
}

float kelvin_to_celsius (float kelvin){
  return (kelvin - 273.15);
}

float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

void categorize_temperature(float celsius){
  if(celsius < 0){
    printf("Temprature category: Freezing\nWeather advisory: Too cold, stay indoors");
  }else if(celsius >= 0 && celsius < 10 ){
    printf("Temprature category: Cold\nWeather advisory: Wear a jacket");
  }else if(celsius >= 10 && celsius < 25){
    printf("Temprature category: Comfortable\nWeather advisory: You should feel comfortable");
  }else if(celsius >= 25 && celsius < 35){
    printf("Temprature category: Hot\nWeather advisory: Wear sunscreen");
  }else{
     printf("Temprature category: Extreme Heat\nWeather advisory: Too hot, stay indoors");
  }
}

int main(){
  float temp;
  int cur_choice;
  int converter;

  printf("Enter the temperature: ");
  scanf("%f", &temp);

  printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
  scanf("%d", &cur_choice);

   if(cur_choice < 1 || cur_choice > 3){
    printf("You entered an invalid option");
    return 0;
   }
   if(cur_choice == 3 && temp < 0){
    printf("You can not input negative Kelvin");
    return 0;
    }

  printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
  scanf("%d", &converter);
  if(converter < 1 || converter > 3){
    printf("You entered an invalid option");
    return 0 ;
  }
  if(cur_choice == 1){
    if(converter == 1){
      printf("Invalid conversion choice");
      return 0;
    }else if(converter == 2){
      printf("Temperature in Farenheit: %.2f °F\n",celsius_to_fahrenheit(temp));
    }else if(converter == 3){
      printf("Temperature in Kelvin: %.2f K\n", celsius_to_kelvin (temp));
    }

  }else if(cur_choice == 2){
      if(converter == 1){
         printf("Temperature in Celsius: %.2f °C\n", fahrenheit_to_celsius(temp));
      }else if(converter == 2){
         printf("Invalid conversion choice");
         return 0;
      }else if (converter == 3){
        printf("Temperature in Kelvin: %.2f K\n", fahrenheit_to_kelvin(temp));
      }

  }else if(cur_choice == 3){
    if(converter == 1){
       printf("Temperature in Celsius: %.2f °C\n", kelvin_to_celsius(temp));
    }else if (converter == 2){
      printf("Temperature in Farenheit: %.2f °F\n",kelvin_to_fahrenheit(temp));
    }else if(converter == 3){
       printf("Invalid conversion choice");
       return 0;
    }
    
  }
   if (cur_choice == 1) {
        categorize_temperature(temp); // temp is already in Celsius
    } else if (cur_choice == 2) {
        categorize_temperature(fahrenheit_to_celsius(temp)); // convert to Celsius for categorization
    } else if (cur_choice == 3) {
        categorize_temperature(kelvin_to_celsius(temp)); // convert to Celsius for categorization
    }
}




