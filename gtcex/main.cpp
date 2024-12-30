#include <iostream>

using namespace std;

int prime(int x)
{
    if(x<2)
        return 0;
    if(x>2&&x%2==0)
        return 0;
    for(int d=3;d*d<=x;d+=2)
        if(x%d==0)
        return 0;
    return 1;

}
int main()
{
    int nr_prime=0;
    for(int i=2;i<168;i++)
        if(prime(i)==1)
        nr_prime++;
    cout<<nr_prime;
}
