#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <typeinfo>
using namespace std;

int binaryToDecimal(string& binary);
int mult(int x, int y);
string decimalToBinary(int decimal,int n);
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
    while(input1.length()<8){
        input1="0"+input1;
    }
    while(input2.length()<8){
        input2="0"+input2;
    }
    a=input1.substr(0,4);
    b=input1.substr(4,8);
    c=input2.substr(0,4);
    d=input2.substr(4,8);

    cout<<a<<"\n "<<b<<" \n"<<c<<" \n"<<d<<endl;
    //8 is the number of bits the binary number will have. We know this because a and c are 4 bits each.
    //TODO: Change with variable length of inputs?
    string ac=decimalToBinary(mult(binaryToDecimal(a),binaryToDecimal(c)),8);
    string bd=decimalToBinary(mult(binaryToDecimal(b),binaryToDecimal(d)),8);
    string ad=decimalToBinary(mult(binaryToDecimal(a),binaryToDecimal(d)),8);
    string bc=decimalToBinary(mult(binaryToDecimal(b),binaryToDecimal(c)),8);
    while(ac.length()<8){
        ac="0"+ac;
    }
    while(bd.length()<8){
        bd="0"+bd;
    }
    while(ad.length()<8){
        ad="0"+ad;
    }
    while(bc.length()<8){
        bc="0"+bc;
    }
    cout<<"A*C = "<<ac<<endl;
    //TODD: should n always just be set to 8?
    int n=8;
    //I think we can just concatenate the ac and bd strings here. sum1 represents 2^n(ac)+bd
    string sum1=ac+bd;
    cout<<"SUM1: "<<sum1<<endl;
    //sum2 represents 2^n/2 (ad+bc)
    string sum2=decimalToBinary(stoi(addBinaries(ad,bc)),8);
    for(int i=0;i<n/2;i++){
        sum2=sum2+"0";
    }
    cout<<"SUM2: "<<sum2<<endl;
    cout<<"FINAL SUM: "<<decimalToBinary(stoi(addBinaries(sum1,sum2)),16)<<endl;

    return 0;
}
string decimalToBinary(int decimal,int n=8){
    string binary="";
    for(int i=0;i<n;i++){
        binary=to_string(decimal%2)+binary;
        decimal=decimal/2;
    }
    return binary;
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

	bitset<16> bin1(num1);
	bitset<16> bin2(num2);
	cout << bin1 << " and " << bin2 << endl;
	cout << typeid(bin1).name() << endl;
	// Add together
	cout << "bin 1: " << bin1.to_ulong() << endl;
	cout << "bin 2: " << bin2.to_ulong() << endl;
	cout << "sum: " << bin1.to_ulong() + bin2.to_ulong() << endl;
    return to_string(bin1.to_ulong()+bin2.to_ulong());
}