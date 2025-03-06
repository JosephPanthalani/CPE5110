//03-05
// Simulate the add-and-shift mulitiplication scheme
// Review the bitset class 03/05
#include <iostream>
#include <bitset>
#include <iomanip>
#include <string>
#include <typeinfo>

using namespace std;

/*
What we need:
1. Binary input (Base 2)
2. Two operands of same length
3. Check the bit at the end of 2nd operand (comparison)
4. Need a product container (array, maybe linked list)
5. Check the number of shifts
6. On last shift, split the product (the elements need to be filled in their respective array or list)
7. Finally subtract complemeent of second operand to R
*/
// Global Variables
int shiftCount = 0;
constexpr int opLength = 0;
string op1, op2;

// Prototypes

// function that stores the arrays of the operands
// This function fills the arrays with their original bit by bit values

// function performs the add-and-shift behavior then computes
// the values for R and Q.

void addAndShift(string A, string Q, string B);
void normalized(string B);
void addBinaries(string num1, string num2);

// Definitions

void addBinaries(string num1, string num2) {
	cin >> num1;
	cin >> num2;
	cout << endl;
	cout << num1 << " and " << num2 << endl;
	bitset<8> bin1(num1);
	bitset<8> bin2(num2);
	cout << bin1 << " and " << bin2 << endl;
	cout << typeid(bin1).name() << endl;
	// Add together
	cout << "bin 1: " << bin1.to_ulong() << endl;
	cout << "bin 2: " << bin2.to_ulong() << endl;
	cout << "sum: " << bin1.to_ulong() + bin2.to_ulong() << endl;
}

void addAndShift(string A, string Q, string B) {
	//Splitting happens in main to get A and Q
	
	//Note: changed the parameters from integer array to string.
	//Convert the strings to base 2 numbers.;
	char Qn = Q[Q.size()-1];
	//bitset<16> conditionBit(Q[Q.size()-1]);
	//bitset<16> lastBit(Qn);
	bitset<16> binNumA(A);
	cout << "Last bit of Q: " << Q[Q.size()-1] << endl;
	/*
	cout << "Last bit passing Qn " << lastBit << endl;//produces 000000000011001
	cout << "Qn using Q: " << conditionBit << endl; //produces 000000000011001
	*/
	cout << "Qn using Qn: " << Qn << endl;
	cout << "Multiplicand A: " << binNumA << endl;
}
int main() {
	
	
	
	string multiplicand, multiplier;
	cout << "Enter the multiplicand:" << endl;
	cin >> multiplicand;
	cout << "Enter the multiplier:" << endl;
	cin >> multiplier;
	string A = multiplicand.substr(0, multiplicand.size()/2);
	string Q = multiplicand.substr((multiplicand.length())/2);
	bitset<16> binA(A);
	bitset<16> binQ(Q);
	bitset<16> binB(multiplier);
	cout << "A: " << binA << endl;
	cout << "Q: " << binQ << endl;
	cout << "B: " << binB << endl;
	cout << endl << endl;
	cout << "Add-and-Shift" << endl;
	addAndShift(A, Q, multiplier);
	
	
	
	/*
	int size;
	cout << "Let's multiply two unsigned binary numbers. Please enter the number of bits for your operands" << endl;
	// Be sure the number of bits is between 4 and 16
	cin >> size;
	cout << "Enter A, your first operand: " << endl;
	cin >> op1;	
	bitset<16> firstOp(op1); // Input will be converted from string to base 2
	cout << "Enter B, your second operand: " << endl;
	cin >> op2;
	bitset<16> secondOp(op2); 
	cout << "1st Operand: " << firstOp << endl << "2nd Operand: " << secondOp << endl; 
    cout << "Enter a random integer " << endl;
    */
	return 0;
}
