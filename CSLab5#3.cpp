/*
  Author: Ryan Huesca
  Course: 136;
  Instructor: Professor Nikolaev
  Assignment: Lab 5 #3
 
  This program takes an input and reverses it then outputs the reverse
  table for the new argument. Range is inclusive [-1023, 1023].
*/

#include <iostream>
using namespace std;

// This function changes the initial argument.
// Uses pass by reference to pass over the new value.
void reverseInPlace(int &n) {
    int left = 0;
    int reverse = 0;
    do {
        left = n % 10;
        reverse = (reverse * 10) + left;
        n = n / 10;
    }
    while (n != 0);
    n = reverse;
}
// Once the argument has been reversed this reverses it for the table
int reverseCall(int n) {
    int left = 0;
    int reverse = 0;
    do {
        left = n % 10;
        reverse = (reverse * 10) + left;
        n = n / 10;
    }
    while (n != 0);
    return reverse;
}
// Asks the user for the input and calls on functions to first
// change the argument then output the table for it.
void reversePos(int n) {
    int z;
    int j = 1;
    do {
        cout << "Please enter your number" << endl;
        cin >> n;
    }
    while (n < -1023 || n > 1023);
    reverseInPlace(n);
    // "z" preserves the original input/"y" since it will
    // change throughout the function
    z = n;
    if (n > 0) {
        do {
            cout << n << "    ";
            cout << reverseCall(n) << endl;
            j++;
            n = z * j;
        }
        while (n <= 1023);
    }
    if (n < 0) {
        do {
            cout << n << "    ";
            cout << reverseCall(n) << endl;
            j++;
            n = z * j;
        }
        while (n >= -1023);
    }
}

int main() {
    int n;
    reversePos(n);
    return 0;
}
