#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Enter a number" << endl;
    int number{};

    cin >> number;


//    This *if* is necessary to rule out numbers out of our test range
    if (number > 1000) {
        cout << "Error number less tan 1000:";
        return 0;
    }

    string array[]{"zero", "one", "two", "three", "four", "five",
                   "six", "seven", "eight", "nine", "ten", "eleven",
                   "twelve", "thirteen", "fourteen", "fifteen",
                   "sixteen", "seventeen", "eighteen", "nineteen",
                   "twenty", "thirty", "forty", "fifty", "sixty",
                   "seventy", "eighty", "ninety"};

    if (number > 100) {
        int leftmost_digit = static_cast<int> ( number / 100 );
        cout << array[leftmost_digit] << " hundred ";

//        We do this so as to remove the leftmost digit from  *number*
//        allowing us to deal with the remaining digits
        number -= leftmost_digit * 100;
    }

//    For numbers between 20 and 100
    if (number > 20) {
        int leftmost_digit = static_cast<int> (number / 10);

        // The index of "twenty" in *array* is 18, hence we use 18 below
        cout << array[18 + leftmost_digit] << " ";
        number -= leftmost_digit * 10;
    }

    // number less than 20
    cout << array[number];
}
