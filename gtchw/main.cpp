#include <bits/stdc++.h>

int verify_permutation(int arr[],int n)
{
    int len=sizeof(arr)/sizeof(arr[0]);
    if(len!=n)
        return 0;
    for(int i=1; i<=n; i++)
    {
        int found=0;
        for(int j=0; j<n; j++)
        {
            if(arr[j]==i)
                found++;
        }

        if(found!=1)
            return 0;


    }
    return 1;

}
void printPermutation(int arr[],int n)
{
    for(int i=0; i<n; i++)
        std::cout<<arr[i]<<' ';

}
int  factorial(int n)
{
    int prod=1;
    for(int i=2;i<=n;i++)
        prod*=i;
    return prod;
}
void NextPermutation(int arr[],int n)
{
    int i,j;
    i=n-2;
    while(arr[i]>arr[i+1])
        i--;
    j=n-1;
    while(arr[j]<arr[i])
        j--;
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
    for(int k=0; k<floor((n-i-1)/2); k++)
    {
        tmp=arr[i+1+k];
        arr[i+1+k]=arr[n-1-k];
        arr[n-1-k]=tmp;
    }


}
int rank_p(int arr[], int n) {
    if (n == 1)
        return 0;
    int q[100001],idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[0])
            q[idx] = arr[i];
         else
            q[idx] = arr[i] - 1;

        idx++;
    }
    return rank_p(q, n - 1) + (arr[0] - 1) * factorial(n - 1);
}
int compare(int arr[],int perm[],int n)
{
    for(int j=0; j<n; j++)
        if(arr[j]!=perm[j])
            return 0;
    return 1;
}
int hasNextPermutation(int arr[],int n)
{
    for(int i=0;i<n;i++)
        if(arr[i]<arr[i+1])
        return 1;
    return 0;
}
int copy_arr(int copyarr[],int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        copyarr[i]=arr[i];
    }
}
int main()
{
    int i,arr[10001],n,r;
    int option;
    std::cout<<std::endl<<std::endl<<"GTC HOMEWORK COURSE 2"<<std::endl;
    std::cout<<"1.Verify if a sequence of n numbers is a permutation or not.\n";
    std::cout<<"2.Display the permutation of rank r of a number n\n";
    std::cout<<"3.Print the rank of a permutation\n";
    std::cout<<"4.Display the inverse of a permutation\n";
    std::cout<<"5.Print the next permutation in lexicographic order of a permutation\n";
    std::cout<<"6.Print the previous permutation in lexicographic order of a permutation\n";
    std::cout<<"Choose[1-6]:";
    std::cin>>option;
    if(option==1)
    {
        std::cout<<"Enter n:";
        std::cin>>n;
        std::cout<<"Enter the sequence of n numbers:";
        for(i=0; i<n; i++)
            std::cin>>arr[i];
        if(verify_permutation(arr,n)==1)
            std::cout<<"is a permutation";
        else
            std::cout<<"not a permutation";
    }
    if(option==2)
    {
        std::cout<<"Enter n:";
        std::cin>>n;
        std::cout<<"Enter r:";
        std::cin>>r;
        for(i=0; i<n; i++)
        {
            arr[i]=i+1;
        }
        std::cout<<"The permutation of rank "<<r<<" is:\n";
        for(i=1; i<=r; i++)
            NextPermutation(arr,n);
        printPermutation(arr,n);
    }
    if(option==3)
   { //Version 1
        int perm[10001],r=0,ok;

        std::cout<<"Enter n:";
        std::cin>>n;
        for(i=0; i<n; i++)
        {
            arr[i]=i+1;
        }
        std::cout<<"Enter the permutation:";
        for(int i=0; i<n; i++)
            std::cin>>perm[i];
        if (compare(arr, perm, n) == 1)
        {
            std::cout << "The rank of the permutation is: " << r << std::endl;
            return 0;
        }

        for(int i = 1; i < factorial(n); i++)
        {
            NextPermutation(arr, n);
            r++;
            if(compare(arr, perm, n) == 1)
            {
                std::cout << "The rank of the permutation is: " << r << std::endl;
                return 0;
            }
        }
    }
    if(option==4)
    {
        std::cout<<"Enter n:";
        std::cin>>n;
        std::cout<<"Enter the permutation:";
        for(i=0;i<n; i++)
            std::cin>>arr[i];
        std::cout<<"The inverse of the permutation is: ";
        for (i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            if (arr[j]==i+1)
                {
                    std::cout<<j+1<<" ";
                    break;
                }

        }
    }
    if(option==5)
    {
        std::cout<<"Enter n:";
        std::cin>>n;
        std::cout<<"Enter the permutation:";
        for(int i=0; i<n; i++)
            std::cin>>arr[i];
        if(hasNextPermutation(arr,n)==0)
        {std::cout<<"This is the last permutation.";
        return 0;}
        NextPermutation(arr, n);
        printPermutation(arr,n);
    }

    if(option==6)
    {
        int perm[100001],prev[100001];
        std::cout<<"Enter n:";
        std::cin>>n;
        for(i=0; i<n; i++)
        {
            arr[i]=i+1;
        }
        std::cout<<"Enter the permutation:";
        for(i=0; i<n; i++)
            std::cin>>perm[i];
        if(compare(arr,perm,n)==1)
        {std::cout<<"This is the first permutation.It doesn't have any previous permutations.";
        return 0;
        }
        for(i=0;i<factorial(n);i++)
        {
            copy_arr(prev,arr,n);
            NextPermutation(arr,n);
            if(compare(arr,perm,n)==1)
            { std::cout<<"The previous permutation is: ";
              printPermutation(prev,n);
            }

        }

    }

}
