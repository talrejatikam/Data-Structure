/*
 Nearest Smallest Right
 input arr[] :{4,5,2,10,8}
 output arr[] : {2,2,-1,8,-1}
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    vector<int> v;
    stack<int> s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
           v.push_back(-1);
        else if(s.size()>0 && s.top()< arr[i])
            v.push_back(s.top());
        else if(s.size()>0 && s.top()>=arr[i])
         {
             while(s.size()>0 && s.top()>=arr[i])
                s.pop();
            if(s.size()==0)
            v.push_back(-1);
            else
             v.push_back(s.top());
         }
         s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++)
      cout<<v[i]<<" ";
}