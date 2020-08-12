/*
Rain water trapping 
input arr[] : {3, 0, 0, 2, 0, 4}
output :10

for each index fina the maximum left value and maximum right value - value at i whole submisssion
*/

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
    cin>>arr[i];
     int mxl[n],mxr[n];
    mxl[0]= arr[0];
    for(int i=1;i<n;i++)
       mxl[i] = std::max(mxl[i-1],arr[i]);
    mxr[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--)
      mxr[i] = std::max(mxr[i+1],arr[i]);
    
    int water[n];
    int sum=0;
    for(int i=0;i<n;i++)
      water[i]= std::min(mxl[i],mxr[i])-arr[i];
     // sum =  sum + water[i];
      
       for(int i=0;i<n;i++)
         sum = sum+water[i];
       cout<<sum;
   
}