#include "BigInt.h"
#include <map>

//int goldRabbits(int);
BigInt goldRabbits(BigInt);
int main() {
    BigInt B1("1123132516131512351");
    BigInt     B2("123561313257248");

    BigInt MAX(__INT_MAX__);
    //MAX.print();
    //(B2+B1).print();
    // B2.print();
    //B1.print();
    // cout << "B1 <= B2? " << (B1<=20?"yes":"no") << endl;
    // B1.print();
    // B2.print();
    // cout << B1;
    // cout << "B1 <= B2? " << (B1<=10?"yes":"no") << endl;

    // (B1-1).print();
    // (B1-2).print();

    // for (BigInt i = 0; i <= 3000; i++)
    // {
    //     //cout << i << endl;
    //     cout << "goldRabbits("<<i<<") = " << goldRabbits(i) << endl;
    // }

    cout << goldRabbits(3) << endl;
    


}

BigInt goldRabbits(BigInt n) {
    static map<BigInt,BigInt> rabbitMap;
    if (n == 1 || n == 0) {
        rabbitMap[n] = 1;
    } else {
        cout << "n-1 - " << n-1 <<endl;
        cout << "n-2 - " << n-2 <<endl;
        rabbitMap[n] = rabbitMap[n-1]+rabbitMap[n-2];
        cout << "rabbitMap[n]: " ; 
    }
    return rabbitMap[n];
}