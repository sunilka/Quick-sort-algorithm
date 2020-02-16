#include<bits/stdc++.h>
using namespace std;

int part(int a[],int low,int high)
{
    int key = low;
    while(1)
    {
        while( a[low] <= a[key] ) low++;
        while( a[high] > a[key] ) high--;

        if(low<high)
            swap(a[low],a[high]);
        else
           {
               swap(a[key],a[high]);
               return high;
           }
    }
}

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int k = part(a,low,high);
        quicksort(a,low,k-1);
        quicksort(a,k+1,high);
    }
}

int main()
{
    int n;
    cout<<"please enter the number of elements in the array \n";
    cin>>n;

    int a[n];
    cout<<"Please enter the array elements :\n";
    for(int i=0;i<n;i++)
        cin>>a[i];

    quicksort(a,0,n-1);

    printf("\n the elements of the array after sorting is :\n");
    for(int i=0;i<n;i++)
        printf("%3d ",a[i]);
}
