#include "BigInt.h"

BigInt::BigInt()
{
}

BigInt::BigInt(string input)
{
    for (int i = input.size() - 1; i >= 0; i--)
    {
        chAr.push_back(input[i]);
    }
}

BigInt::BigInt(int num)
{
    string temp = to_string(num);
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        chAr.push_back(temp[i]);
    }
}

BigInt::BigInt(const BigInt &other)
{
    for (int i = 0; i < other.chAr.size(); i++)
    {
        chAr.push_back(other.chAr.at(i));
    }
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
    int i = 0;
    chAr.at(i) += 1;
    //cout << chAr.at(i) <<endl;
    while (int(chAr.at(i) - '0') / 10 > 0)
    {
        char temp = (chAr.at(i) - '0') / 10;
        //cout << "temp: " << int(temp) << endl;
        chAr.at(i) = ((chAr.at(i) - '0') % 10) + '0';
        if (i + 1 < chAr.size())
        {
            chAr.at(i + 1) += temp;
        }
        else
        {
            chAr.push_back(temp + '0');
        }
        i++;
    }
    return *this;
}

BigInt BigInt::operator-(BigInt n) const
{
    BigInt abuse(*this);
    int i = 0;

    abuse.chAr[i] -= (n == 1 ? 1 : 2);

    while (i < abuse.chAr.size())
    {
        if (int(abuse.chAr[i]) < 48 && 2 <= abuse.chAr.size())
        {
            abuse.chAr[i + 1] -= 1;
            abuse.chAr[i] += 10;
        }
        i++;
    }

    if ( int(abuse.chAr[i-1]) == 48 && abuse.chAr.size() != 1) {
        abuse.chAr.pop_back();
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
    //cout << "RUN" << endl;
    BigInt abuse(*this);
    if (abuse.chAr.size() >= other.chAr.size())
    {
        int i = 0;
        int j = 0;
        cout << "this: ";
        abuse.print();
        cout << "other: ";
        other.print();
        abuse.chAr[i] += other.chAr[i] - '0';
        cout << "Entry: " << int(abuse.chAr[i]-'0') << endl;
        while (i < other.chAr.size())
        {
            cout << "loop:" << endl;
            char carry = (abuse.chAr.at(i) - '0') / 10;
            cout << "carry: " << int(carry) << endl;
            abuse.chAr.at(i) = ((abuse.chAr.at(i) - '0') % 10) + '0';
            cout << "new chAr[" << i << "] = " << abuse.chAr[i] << endl;

            if (i + 1 < other.chAr.size())
            {
                cout << "first case" << endl;
                abuse.chAr[i + 1] += carry + (other.chAr[i + 1] - '0');
            }
            else if (i + 1 < abuse.chAr.size())
            {
                cout << "storing index to clean up from\n";
                j = i + 1;
                abuse.chAr[j] += carry;
                cout << "new chAr[" << j << "] = " << abuse.chAr[j] << endl;
            } 
            else if (int(carry) != 0) {
                cout << "did it just do this " << endl;
                abuse.chAr.push_back(carry+'0');
            }
            i++;
        }
        cout << "Starting clean up from: " << j << " index\n";
        cout << "while check " << int(abuse.chAr.at(j) - 48) << endl;
        while (int(abuse.chAr.at(j) - 48) / 10 > 0)
        {
            cout << "clean up index " << j << "\n";
            char carry = (abuse.chAr.at(j) - '0') / 10;
            cout << "carry: " << int(carry) << endl;
            abuse.chAr.at(j) = ((abuse.chAr.at(j) - '0') % 10) + '0';
            cout << "new chAr[" << j << "] = " << chAr[i] << endl;
            if (j + 1 < chAr.size())
            {
                abuse.chAr.at(j + 1) += carry;
            }
            else
            {
                abuse.chAr.push_back(carry + '0');
            }
            j++;
        }
    }
    else
    {
        return other + abuse;
    }
    return abuse;
}

BigInt BigInt::operator=(BigInt other)
{
    chAr = other.chAr;
    return *this;
}

BigInt BigInt::operator=(int n)
{
    BigInt temp(n);
    chAr = temp.chAr;
    return *this;
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
    return *this < BigInt(n);
}

bool BigInt::operator<(const BigInt &other) const
{
    bool notLess = true;
    if (chAr.size() == other.chAr.size())
    {
        int i = chAr.size() - 1;
        while (i >= 0 && notLess)
        {
            if (int(chAr[i]) < int(other.chAr[i]))
            {
                notLess = false;
            }
            i--;
        }
    }
    else if (chAr.size() < other.chAr.size())
    {
        notLess = false;
    }
    return !notLess;
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
        cout << chAr.at(i);
    }
}

ostream &operator<<(ostream &post, BigInt temp)
{
    //cout << "OSTREAM" << endl;
    if (temp.getChAr().size() > 12)
    {
        for (int i = temp.getChAr().size() - 1; i >= temp.chAr.size() - 12; i--)
        {
            post << temp.getChAr()[i];
            if (i == temp.getChAr().size() - 1)
            {
                post << ".";
            }
        }
        post << "e^" << temp.getChAr().size() - 1 << endl;
    }
    else
    {
        temp.print();
    }
}