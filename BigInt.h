#ifndef BIG_INT_H
#define BIG_INT_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class BigInt {
    private:
        vector<char> chAr;
    public:
        BigInt();
        BigInt(string);
        BigInt(int);
        BigInt(const BigInt&);
        ~BigInt();
        vector<char> getChAr();
        BigInt operator+(BigInt) const;
        BigInt operator+(int);
        BigInt operator++(int);
        BigInt operator-(int);
        BigInt operator-(BigInt) const;
        BigInt operator=(BigInt);
        BigInt operator=(int);
        bool operator==(int);
        bool operator==(const BigInt&) const;
        bool operator<(int);
        bool operator<(const BigInt&) const;
        bool operator<=(int);
        bool operator<=(const BigInt&) const;
        friend std::ostream & operator<<(std::ostream &os,BigInt);
        void print();





};

#endif