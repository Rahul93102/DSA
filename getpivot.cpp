#include<iostream>
using namespace std;

int getpivot(int arr[] , int n ){ 
    int s = 0;
    int e = n - 1;
    int m = s + (e -  s)/2;

    while(s <= e){ 
        if(arr[m] > arr[0]){ 
            s = m + 1;
        }else { 
            e = m;
        }
        m = s + (e - s)/2;
    }
    return s;
}

int main(){ 
    int arr[] = {8,10,17,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = getpivot(arr,n);
    cout <<" the pivot element is: "<< ans <<endl;

}