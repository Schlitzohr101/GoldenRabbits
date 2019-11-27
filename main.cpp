//William Murray
//CECS 282-05
//Prog - 5 Golden Rabbits
//Nov 21, 2019
#include "BigInt.h"
#include <map>
#include <iterator>
#include <time.h>

BigInt goldRabbits(BigInt);
int main() {
    
    BigInt B1("123456789123456789123456789123456789");
    BigInt B2(B1);
    BigInt MAX(__INT_MAX__);
    cout << "B1:"<<B1<<"\nB2:"<<B2<<"\nMAX:"<<MAX<<endl;

    cout << "\nB1:";
    B1.print();
    cout<<endl;

    for(BigInt i = 0; i<3001;i++){
        cout << "\ngoldRabbits("<< i <<") = " << goldRabbits(i);
    }
    //cout << goldRabbits(BigInt(3000));
    cout << "\nThis is the value of goldRabbits(3000)\n\n";
    BigInt gR3000 = goldRabbits(BigInt(3000));
    gR3000.print();
    cout << endl;

    return 0;
}

BigInt goldRabbits(BigInt n) {
    static map<BigInt,BigInt> rabbitMap;
    //cout << "n: " << n << endl;
    // rabbitMap[n] = (n == 0 || n == 1) ? BigInt(1) : 
    //     (rabbitMap[n - 1] == 0 ? goldRabbits(n-1):rabbitMap[n-1]) + (rabbitMap[n - 2] == 0?goldRabbits(n-2):rabbitMap[n-2]);
    if (n == 0 || n == 1) {
        rabbitMap.insert(pair<BigInt,BigInt>(n,BigInt(1)));
    } else {
        BigInt temp = (rabbitMap[n-1] + rabbitMap[n-2]);
        //cout << "\nn-1 + n-2 = " << temp << endl;
        rabbitMap.erase(n);
        rabbitMap.insert(pair<BigInt,BigInt>(n,temp)); 
    }
    return rabbitMap.at(n);
    
}