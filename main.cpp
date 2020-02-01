#include <iostream>

using namespace std;


// Write a program that prints odd numbers between 0 and 100
int main() {
    for (int num = 0; num < 100; num++) {
        // Checks to see if num / 2 gives a remainder of 1
        if (num % 2 == 1) {
            cout << num << endl;
        }
    }

}
