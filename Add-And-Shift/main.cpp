//Final modification to add-and-shift algorithm

#include <iostream>
#include <bitset>
#include <string>
#include <vector>

using namespace std;
// Declare all the binary numbers as unsigned.
unsigned int decA, decB, product, A;

int carrySelectEquation(int n) {
	int executionTime = (10+((n-4)/4)*2); //time to execution addition operation
    return executionTime;  
}
unsigned int binToDec(const string &binary) {
    return bitset<16>(binary).to_ulong(); // binary to decimal
}
// Function to perform Add-and-Shift Multiplication and compute execution time
void addAndShiftMultiplication(string op1, string op2) {
	int delay = 0;  // execution time in terms of delta t
    decA = binToDec(op1);  // Convert binary to decimal (actally converts string to unsigned long 16 bit binary) 
    decB = binToDec(op2);  // Convert binary to decimal
    product = 0;  
    A = decA; // Store the adjusted value of A. Should shift the same amount of times as bit size of multiplier.   
    // Add and shift or just shift
    for (int i = 0; i < op2.length(); i++) {
    	// Track the bit of b
        if (decB%2 == 1) {  // if the last bit of b is 1 (to represent Qn)
            product += A; // Add the multiplicand to the product
            cout << "A: " << bitset<16>(A) << endl; // display A
            int length = op2.length();
            delay += carrySelectEquation(length); // Addition delay
        } else {
        	cout << "Shift A" << endl;
        	cout << "A: " << bitset<16>(A) << endl; // display A
            //ncout << "Shift Right -> ";
        }
        delay += 3; // increment execution time
        cout << "Adjusted A + Current Product: " << bitset<16>(product) << endl << endl;
        decB >>= 1; // shift the bit under condition
        A <<= 1; // shift A 
    }
    cout << endl << endl << endl;
    cout << "Product: " << bitset<16>(product) << " in hex: " << hex << product << endl;
    cout << "Total Execution Time: " << dec << delay << " delta t" << endl;
}

int main() {
	char option;
    do {
    	string multiplicand;
        cout << "Enter the multiplicand: " << endl;
        cin >> multiplicand;
        string multiplier;
        cout << "Enter the multiplier: ";
        cin >> multiplier;
        addAndShiftMultiplication(multiplicand, multiplier);
        
        cout << "Would you like to enter another set of operands? (y/n): ";
        cin >> option;
    } while (option == 'y' || option == 'Y');
    return 0;
}
