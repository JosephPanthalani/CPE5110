#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <typeinfo>
using namespace std;

int binaryToDecimal(string& binary);
int mult(int x, int y);
string decimalToBinary(long long decimal,int n);
string addBinaries(string num1,string num2);
int main() {
    string a;
    string b;
    string c;
    string d;
    string word1;
    string word2;
    string input1;
    string input2;
    cin>>input1;
    cin>>input2;
    
    //Add zeroes at the end because 4x4 multiplier as building block
    while(input1.length()!=4 && input1.length()!=8 && input1.length()!=12 && input1.length()!=16){
        cout<<"INPUT1: "<<input1.length();
        input1="0"+input1;
    }
    while(input2.length()!=4 && input2.length()<8 && input2.length()<12 && input2.length()<16){
        cout<<"INPUT2: "<<input2.length();
        input2="0"+input2;
    }
 
    a=input1.substr(0,input1.length()/2);
    b=input1.substr(input1.length()/2,input1.length());
    c=input2.substr(0,input2.length()/2);
    d=input2.substr(input2.length()/2,input2.length());
    int binaryLength=input1.length() *2;
    int inputLength=input1.length();
    cout<<"a: "<<a<<"\n "<<"b: "<<b<<" \n"<<"c: "<<c<<" \n"<<"d: "<<d<<endl;
    //8 is the number of bits the binary number will have. We know this because a and c are 4 bits each.
    
    string ac=decimalToBinary(mult(binaryToDecimal(a),binaryToDecimal(c)),inputLength);
    string bd=decimalToBinary(mult(binaryToDecimal(b),binaryToDecimal(d)),inputLength);
    string ad=decimalToBinary(mult(binaryToDecimal(a),binaryToDecimal(d)),inputLength);
    string bc=decimalToBinary(mult(binaryToDecimal(b),binaryToDecimal(c)),inputLength);
    
    
    while(ac.length()<inputLength){
        ac="0"+ac;
    }
    while(bd.length()<inputLength){
        bd="0"+bd;
    }
    while(ad.length()<inputLength){
        ad="0"+ad;
    }
    while(bc.length()<inputLength){
        bc="0"+bc;
    }
    cout<<"A*C = "<<ac<<endl;
    cout<<"B*D = "<<bd<<endl;
    cout<<"A*D = "<<ad<<endl;
    cout<<"B*C = "<<bc<<endl;
    
    int n=binaryLength;
    //I think we can just concatenate the ac and bd strings here. sum1 represents 2^n(ac)+bd
    string sum1=ac+bd;
    cout<<"SUM1: "<<sum1<<endl;
    //sum2 represents 2^n/2 (ad+bc)
    
    //might need to change binaryLength/2 later
    //string sum2=decimalToBinary(stoll(addBinaries(ad,bc)),binaryLength/2);
    string sum2=addBinaries(ad,bc);
    
    //2^n/2(ad+bc)
    for(int i=0;i<inputLength/2;i++){
        sum2=sum2+"0";
    }
    cout<<"SUM2: "<<sum2<<endl;
    // for(int i=0;i<n/2;i++){
    //     sum2=sum2+"0";
    // }
    string finalAnswer=addBinaries(sum1,sum2);
    while (finalAnswer.length()<sum1.length()){
        finalAnswer="0"+finalAnswer;
    }
    cout<<"FINAL SUM: "<<finalAnswer<<endl;

    return 0;
}
string decimalToBinary(long long decimal,int n){
    string result = "";
    for (int i = n - 1; i >= 0; i--) {
        result += (decimal & (1LL << i)) ? '1' : '0';
    }
    return result;
    // for(int i=0;i<n;i++){
    //     binary=to_string(decimal%2)+binary;
    //     decimal=decimal/2;
    // }
    // return binary;
}
int binaryToDecimal(string& binary){
    int decimal=0;
    for(char bit: binary){
        decimal=decimal*2+(bit-'0');

    }
    return decimal;
}
int mult (int x,int y){
    int prod=0;
    for(int i=x;i>0;i--){
        prod=prod+y;

    }
    return prod;
}



string addBinaries(string num1, string num2) {
    int maxSize = max(num1.length(), num2.length()) + 1; // +1 to account for carry
    bitset<32> bin1(stoull(num1, nullptr, 2)); // Convert string to binary bitset
    bitset<32> bin2(stoull(num2, nullptr, 2)); 

    // Perform addition
    bitset<32> sum = bin1.to_ullong() + bin2.to_ullong();

    // Convert result to a binary string
    string result = sum.to_string();

    // Trim leading zeros
    result = result.substr(result.find('1')); 

    return result;









    // //int maxSize = max(num1.length(), num2.length()) + 1; // +1 to account for the carry bit
	// bitset<32> bin1(num1);
	// bitset<32> bin2(num2);
	// cout << bin1 << " and " << bin2 << endl;
	// cout << typeid(bin1).name() << endl;
	// // Add together
	// cout << "bin 1: " << bin1.to_ulong() << endl;
	// cout << "bin 2: " << bin2.to_ulong() << endl;
	// cout << "sum: " << bin1.to_ulong() + bin2.to_ulong() << endl;
    // return to_string(bin1.to_ulong()+bin2.to_ulong());
}