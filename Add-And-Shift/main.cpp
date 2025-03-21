// Simulate the add-and-shift mulitiplication scheme
// Review the bitset class 03/05
#include <iostream>
#include <bitset>
#include <string>
#include <vector>

using namespace std;

// Function to convert a binary string to an integer
unsigned int binaryToDecimal(const string &binary) {
    return stoi(binary, nullptr, 2);
}

// Function to validate binary input (between 4 to 16 bits)
bool isValidBinary(const string &binary) {
    if (binary.length() < 4 || binary.length() > 16) {
        return false;
    }
    for (char c : binary) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

// Function to perform Add-and-Shift Multiplication
void addAndShiftMultiplication(string multiplicand, string multiplier) {
    unsigned int A = binaryToDecimal(multiplicand);  // Convert binary to decimal
    unsigned int B = binaryToDecimal(multiplier);
    unsigned int product = 0;  // Initialize product to 0
    unsigned int shiftedA = A; // Store the shifting version of A

    cout << "\nStep-by-Step Add-and-Shift Multiplication:\n";
    cout << "---------------------------------------------\n";
    cout << "Multiplicand (A) = " << multiplicand << " (" << A << ")\n";
    cout << "Multiplier (B)   = " << multiplier << " (" << B << ")\n";
    cout << "---------------------------------------------\n";

    int bitCount = multiplier.length(); // Get the number of bits in B
    vector<string> partialProducts;  // Store partial product results

    // Perform bitwise multiplication
    for (int i = 0; i < bitCount; i++) {
        cout << "Step " << i + 1 << ": ";
        
        if (B & 1) {  // Check if LSB of B is 1
            product += shiftedA; // Add the multiplicand to the product
            cout << "Add " << bitset<16>(shiftedA) << " -> ";
        } else {
            cout << "No Add -> ";
        }

        partialProducts.push_back(bitset<16>(product).to_string()); // Store partial sum
        cout << "Partial Product: " << bitset<16>(product) << endl;

        B >>= 1; // Shift the multiplier right
        shiftedA <<= 1; // Shift the multiplicand left
    }

    cout << "---------------------------------------------\n";
    cout << "Final Product: " << bitset<16>(product) << " (" << product << ")\n";
}

int main() {
    string multiplicand, multiplier;

    // Input the multiplicand
    cout << "Enter the binary multiplicand (4-16 bits): ";
    cin >> multiplicand;
    while (!isValidBinary(multiplicand)) {
        cout << "Invalid input. Enter a binary number (4-16 bits): ";
        cin >> multiplicand;
    }

    // Input the multiplier
    cout << "Enter the binary multiplier (4-16 bits): ";
    cin >> multiplier;
    while (!isValidBinary(multiplier)) {
        cout << "Invalid input. Enter a binary number (4-16 bits): ";
        cin >> multiplier;
    }

    // Perform multiplication using add-and-shift method
    addAndShiftMultiplication(multiplicand, multiplier);

    return 0;
}