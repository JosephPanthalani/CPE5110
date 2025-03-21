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
string binaryToHexadecimal(string binary);
int main() {
    string a;
    string b;
    string c;
    string d;
    string word1;
    string word2;
    string input1;
    string input2;
    int executionTime=0;
    cout<<"Enter Binary Input 1: "<<endl;
    cin>>input1;
    cout<<"Enter Binary Input 2: "<<endl;
    cin>>input2;
    
    //Add zeroes at the end because 4x4 multiplier as building block. Stop when it is multiple of 4 
    while(input1.length()!=4 && input1.length()!=8 && input1.length()!=12 && input1.length()!=16){
        cout<<"INPUT1: "<<input1.length();
        input1="0"+input1;
    }
    while(input2.length()!=4 && input2.length()!=8 && input2.length()!=12 && input2.length()!=16){
        cout<<"INPUT2: "<<input2.length();
        input2="0"+input2;
    }
    //To get a,b,c,d we just divide both inputs in half
    a=input1.substr(0,input1.length()/2);
    b=input1.substr(input1.length()/2,input1.length());
    c=input2.substr(0,input2.length()/2);
    d=input2.substr(input2.length()/2,input2.length());

    int binaryLength=input1.length() *2;
    int inputLength=input1.length();
    cout<<"a: "<<a<<"\n "<<"b: "<<b<<" \n"<<"c: "<<c<<" \n"<<"d: "<<d<<endl;
    
    //Each of these 4 multiplications costs 21 delta t according to our 4 buildling blocks of 4x4 multiplier units
    string ac=decimalToBinary(mult(binaryToDecimal(a),binaryToDecimal(c)),inputLength);
    executionTime+=21;
    string bd=decimalToBinary(mult(binaryToDecimal(b),binaryToDecimal(d)),inputLength);
    executionTime+=21;
    string ad=decimalToBinary(mult(binaryToDecimal(a),binaryToDecimal(d)),inputLength);
    executionTime+=21;
    string bc=decimalToBinary(mult(binaryToDecimal(b),binaryToDecimal(c)),inputLength);
    executionTime+=21;
    
    
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
    //We can just concatenate the ac and bd strings here. sum1 represents 2^n(ac)+bd
    string sum1=ac+bd;
    //We shift left the length of bd. For each shift left we add 3 delta t
    executionTime+=bd.length()*3;
    //We don't add carry select adder delay here because 2^n(ac)+bd just counts as a concatenation, not an addition
    cout<<"SUM1: "<<sum1<<endl;
    //sum2 represents 2^n/2 (ad+bc)
    
    
    
    string sum2=addBinaries(ad,bc);
    //Add carry select adder delay again
    executionTime+=10+((inputLength-4)/4)*2;
    
    //2^n/2(ad+bc)
    for(int i=0;i<inputLength/2;i++){
        sum2=sum2+"0";
    }
    //Shift left n/2 times. Each shift add 3 delta t again
    executionTime+=inputLength/2*3;
    cout<<"SUM2: "<<sum2<<endl;

    string finalAnswer=addBinaries(sum1,sum2);
    //Add carry select adder delay again
    executionTime+=10+((inputLength-4)/4)*2;
    while (finalAnswer.length()<sum1.length()){
        finalAnswer="0"+finalAnswer;
    }
    cout<<"FINAL SUM IN BINARY: "<<finalAnswer<<endl;
    cout<<"FINAL SUM IN HEXADECIMAL: "<<binaryToHexadecimal(finalAnswer)<<endl;
    cout<<"Execution time: "<<executionTime<<" delta t"<<endl;

    return 0;
}
string decimalToBinary(long long decimal,int n){
    string result = "";
    for (int i = n - 1; i >= 0; i--) {
        result += (decimal & (1LL << i)) ? '1' : '0';
    }
    return result;

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
}
string binaryToHexadecimal(string binary) {
    string hexadecimal = "";
    for (int i = 0; i < binary.length(); i += 4) {
        string nibble = binary.substr(i, 4);
        if (nibble == "0000") hexadecimal += "0";
        else if (nibble == "0001") hexadecimal += "1";
        else if (nibble == "0010") hexadecimal += "2";
        else if (nibble == "0011") hexadecimal += "3";
        else if (nibble == "0100") hexadecimal += "4";
        else if (nibble == "0101") hexadecimal += "5";
        else if (nibble == "0110") hexadecimal += "6";
        else if (nibble == "0111") hexadecimal += "7";
        else if (nibble == "1000") hexadecimal += "8";
        else if (nibble == "1001") hexadecimal += "9";
        else if (nibble == "1010") hexadecimal += "A";
        else if (nibble == "1011") hexadecimal += "B";
        else if (nibble == "1100") hexadecimal += "C";
        else if (nibble == "1101") hexadecimal += "D";
        else if (nibble == "1110") hexadecimal += "E";
        else if (nibble == "1111") hexadecimal += "F";
    }
    return hexadecimal;
}