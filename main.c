/*
 * This program was designed to help the user know how many elements of the array that they create are unique, scilicet,
 * how many are not repeated.
 * It uses a counter and a struct made up by an integer and a boolean, which will only be true after the number has been
 * processed (analyzed/sort) and determined to be different from any other element of the array.
 *
 * Author: Soraya Maqueda
 * Date: 16.10.2018
 * Contact: soraya_maqueda@hotmail.com
 */
#include <stdio.h>
#include <stdbool.h>

int main() {
    int i;
    int counter = 0; //Here I wil save the times a number is not repeated

    //Here I ask the user for the size of the array.
    printf("How many numbers are you going to introduce?");
    scanf("%i", &i);

    //This structure will help me analyze and sort the numbers that are introduced.
    struct pair {
        int number;
        bool processed;
    }num[i];

    //Here I store the values of the array.
    for(int k = 0; k < i; k++){
        printf("Give me a number: \n");
        scanf("%i", &num[k].number);
        num[i].processed = false;
    }

    //This cycle is to sort the numbers and placing them to the struct.
    for (int s = 0; s < i - 1; s++) {
        if (!num[s].processed) {
            num[s].processed = true;
            bool unique = true;
            for (int j = s + 1; j < i; j++) {
                if(num[s].number == num[j].number) {
                    unique = false;
                    num[j].processed = true;
                }
            }
            if (unique) {
                counter++;
            }
        }
    }

    //This extra if is to analyze the last value of the array, which was omitted due to the nature of the parameters.
    if(!num[i+1].processed){
        counter++;
    }

    printf("The number of unique elements of the array is: %i \n", counter);

    return 0;
}