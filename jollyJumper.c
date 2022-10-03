#include "jollyjumper.h"
#include <stdbool.h>
#include <malloc.h>


//Method 1
int isJollyJumber(const int seq[], int size) {
    bool diffs_found[size-1]; //create array, elemnt is true if difference for coresponding index is found
    for (int i = 1; i < size; i++) {
        diffs_found[abs(seq[i-1]-seq[i])-1] = true; //calculating absolute differences between succesive elements 
    }                                               //and assigns true for that index.
    for (int i = 0; i < size-2; i++) {
        if (diffs_found[i]!=true) {   //if an element in diffs_found isnt true, cant be jolly
            return false;
        }
    }
    return true; //if all true, jolly
}
//Method 2
int isJollyJumber2(const int seq[], int size) {
    /*We can predict what the sum of the differences should be, 1+2+3...+n
      with the following formula: n(n+1)/2
    */
    int sum = 0;
    int predicted_sum = (size-1)*size/2; 
    for (int i = 1; i < size; i++) {
        sum += abs(seq[i-1]-seq[i]); //summing up the absolute differences between succesive elements
    } 
    return sum == predicted_sum ? 1 : 0;  //using ternary operator to return 1 or 0
}