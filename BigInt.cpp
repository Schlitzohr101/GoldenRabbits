#include "BigInt.h"

BigInt::BigInt()
{
    chAr.push_back(0);
}

BigInt::BigInt(string input)
{
    for (int i = input.size() - 1; i >= 0; i--)
    {
        chAr.push_back(input[i]-'0');
    }
}

BigInt::BigInt(int num)
{
    string temp = to_string(num);
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        chAr.push_back(temp[i]-'0');
    }
}

BigInt::BigInt(const BigInt &other)
{
    this->chAr = other.chAr;
}

BigInt::~BigInt()
{
    chAr.clear();
}

vector<char> BigInt::getChAr()
{
    return chAr;
}

BigInt BigInt::operator++(int)
{
   return (*this) = (*this)+1;
}

BigInt BigInt::operator-(BigInt n) const
{
    BigInt abuse(*this);

    while (abuse.chAr.size() != n.chAr.size())
    {
        (abuse.chAr.size() > n.chAr.size() ? n.chAr.push_back(0) : abuse.chAr.push_back(0));
    }

    for (size_t i = 0; i < abuse.chAr.size(); i++)
    {
        if (abuse.chAr[i] < n.chAr[i]) {
            abuse.chAr[i] += 10;
            abuse.chAr[i+1] -= 1;
        }
        abuse.chAr[i] -= n.chAr[i];
        if (abuse.chAr[i] == 0 && n.chAr[i] == 0 && i == abuse.chAr.size()-1)
        {
            abuse.chAr.erase(abuse.chAr.end()-1);
        }
                
    }
    return abuse;
}

BigInt BigInt::operator-(int n)
{
    return (*this) - BigInt(n);
}

BigInt BigInt::operator+(int n)
{
    return (*this) + BigInt(n);
}

BigInt BigInt::operator+(BigInt other) const
{
    //cout << " + " << endl;
    BigInt abuse(*this);

    // cout << "abuse: " << abuse << endl;
    // cout << "other: " << other << endl;

    while (other.chAr.size() != abuse.chAr.size()) {
        if (other.chAr.size() > abuse.chAr.size())
        {
            abuse.chAr.push_back(0);
        } else {
            other.chAr.push_back(0);
        }
    }
    char carry = 0;
    for (int i = 0; i < abuse.chAr.size(); i++)
    {
        if (carry == 1) {
            carry = 0;
            abuse.chAr[i] += 1;
        }
        if (abuse.chAr[i] + other.chAr[i] >= 10)
        {
            carry = 1;
        }
        abuse.chAr[i] += other.chAr[i] - carry * 10;
    }
    if (carry == 1)
    {
        abuse.chAr.push_back(carry);
    }
    return abuse;
}

BigInt BigInt::operator=(BigInt other)
{
    //cout << "other in = : "; other.print(); cout << endl;
    chAr = other.chAr;
    return (*this);
}

BigInt BigInt::operator=(int n)
{
    BigInt temp(n);
    this->chAr = temp.chAr;
    return (*this);
}

bool BigInt::operator==(int n)
{
    return (*this) == BigInt(n);
}

bool BigInt::operator==(const BigInt &n) const
{
    bool isEqual = true;
    if (chAr.size() == n.chAr.size())
    {
        int i = 0;
        while (i < chAr.size() && isEqual)
        {
            if (chAr[i] != n.chAr[i])
            {
                isEqual = false;
            }
            i++;
        }
    }
    else
    {
        isEqual = false;
    }
    return isEqual;
}

bool BigInt::operator<(int n)
{
    return (*this) < BigInt(n);
}

bool BigInt::operator<(const BigInt &other) const
{
    if(*this==other){return false;}
    if(chAr.size()<other.chAr.size()){
        return true;
    }else if(chAr.size()>other.chAr.size()){
        return false;
    }else{
        int index = chAr.size()-1;
        while(index>-1){
            if(chAr[index]>other.chAr[index]){
                return false;
            }else if(chAr[index]<other.chAr[index]){
                return true;
            }
            index--;
        }
        return true;
        
    }
}

bool BigInt::operator<=(int n)
{
    return (*this) <= (BigInt(n));
}

bool BigInt::operator<=(const BigInt &other) const
{
    return (*this) < (other) || (*this) == (other);
}

void BigInt::print()
{
    //cout << "PRINT" << endl;
    for (int i = chAr.size() - 1; i >= 0; i--)
    {
        cout << int(chAr.at(i));
    }
}

ostream &operator<<(ostream &post, BigInt temp)
{
    //post << "OSTREAM" << endl;
    if (temp.getChAr().size() > 11)
    {
        for (int i = temp.getChAr().size() - 1; i >= temp.chAr.size() - 11; i--)
        {
            post << int(temp.getChAr()[i]);
            if (i == temp.getChAr().size() - 1)
            {
                post << ".";
            }
        }
        post << "e^" << temp.getChAr().size() << endl;
    }
    else
    {
        temp.print();
    }
    return post;
}