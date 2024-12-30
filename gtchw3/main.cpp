#include <bits/stdc++.h>
using namespace std;
string convertToBinary(int n,int len)
{
    string binary_number="";
    while(n>0)
    {
        if(n%2==0)
             binary_number.insert(0,"0");
        else
            binary_number.insert(0,"1");
        n=n/2;
    }
    if(binary_number.length()<len)
        while(binary_number.length()!=len)
            binary_number.insert(0,"0");
    return binary_number;

}
string Permutation(char sets[],int nr_el,string binary_num)
{
    string permutation;
    char bits[nr_el];
    strcpy(bits,binary_num.c_str());
    for(int i=0;i<nr_el;i++)
    {
        permutation+=((bits[i]-'0')*sets[i]);

    }
    return "{"+permutation+"}";

}
string GreyBinary(string binary_num,int nr_el)
{
    string grey_bin;
    int nr;
    char bits[nr_el+1];
    strcpy(bits,binary_num.c_str());
    for(int i=0;i<nr_el;i++)
    {
        if(i+1<nr_el)
        nr=(bits[i]+bits[i+1])%2;
        else
        nr=bits[i]%2;

        if(nr==0)
        grey_bin.insert(0,"0");
        else
        grey_bin.insert(0,"1");

    }
    reverse(grey_bin.begin(),grey_bin.end());
    return grey_bin;

}
void reverseArray(char sets[],int start,int end)
{
    if(start >= end)
         return;

    swap(sets[start],sets[end]);
    reverseArray(sets,start+1,end-1);
}
int GreyRank(string grey_bin,int nr_el)
{
    char bits[nr_el+1];
    int nr=0;
    strcpy(bits,grey_bin.c_str());
    for(int i=0;i<nr_el;i++)
        nr+=(bits[nr_el - 1 - i]-'0')*pow(2,i);
    return nr;
}
string GBPermutation(char sets[],int nr_el,string binary_num)
{
    string permutation,final_permutation;
    char bits[nr_el];
    strcpy(bits,binary_num.c_str());
    int j=nr_el-1;
    for(int i=0;i<nr_el;i++)
    {
        if((bits[j]-'0')!=0)
            permutation+=((bits[j]-'0')*sets[i]);
        j--;

    }
    permutation[nr_el]='\0';
    return "{"+permutation+"}" ;

}
int main()
{
    int n;
    char sets[1001];
    string grey_permutation[1001];
    string bit_string,initial_bit_string,grey_binary;
    cout<<"Enter number of elements:";
    cin>>n;
    int nr=pow(2,n);
    string permutations[nr];
    cout<<"Enter the set:";
    for(int i=0;i<n;i++)
        cin>>sets[i];
    cout<<"General method:"<<endl;
    cout<<"Rank"<<"     "<<"Bit string"<<"      "<<"Permutation"<<endl;
    for(int i=0;i<pow(2,n);i++)
    {bit_string=convertToBinary(i,n);
     cout<<i<<"          "<<bit_string<<"             "<<Permutation(sets,n,bit_string)<<"     "<<endl;
    }
    cout<<endl;
    cout<<"Grey Method:"<<endl;
    for(int i=0;i<pow(2,n);i++)
    {bit_string=convertToBinary(i,n);
     initial_bit_string=bit_string;
     reverse(bit_string.begin(),bit_string.end());
     grey_binary=GreyBinary(bit_string,n);
     int grey_rank=GreyRank(grey_binary,n);
     cout<<grey_binary<<" "<<GBPermutation(sets,n,grey_binary)<<endl;
     grey_permutation[i]=GBPermutation(sets,n,grey_binary);
    }
    cout<<"1.Unrank Grey method\n";
    cout<<"2.Next Grey rank subset\n";
    int opt;
    cout<<"Choose option[1-2]:";
    cin>>opt;
    if(opt==1)
    {
        cout<<"Choose rank:";
        int rank;
        cin>>rank;
        cout<<"The Grey permutation of rank "<<rank<<" is "<<grey_permutation[rank];
    }
    if(opt==2)
    {

        cout<<"Enter subset(Format {.....}):";
        string grey_subset;
        cin>>grey_subset;

        if(grey_subset.find(",")!=std::string::npos)
        {
            cout<<"Don't use commmas! Keep the format identical to the ones above";
            cin>>grey_subset;
        }
        int value=pow(2,n);

        for(int i=0;i<value;i++)
        {if(i<value-1&&grey_permutation[i]==grey_subset)
            {cout<<"Next permutation is:"<<grey_permutation[i+1];
            break;}
         if(i==value-1)
            cout<<grey_subset<<" is the last permutation";
        }

       }


}
