/*
 Stock Span Problem
 input arr[] :{100,80,60,70,60,75,85}
 output arr[] : {1,1,1,2,1,4,6}
*/

#include <iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    
    vector<int> v;
    stack <pair<int, int>> s;
    for(int i=0;i<n;i++)
      {
          if(s.size()==0)
            v.push_back(-1);
        else if(s.size()>0 && s.top().first>arr[i])
        v.push_back(s.top().second);
        else if(s.size()>0 && s.top().first<=arr[i])
        {
            while(s.size()>0 && s.top().first<=arr[i])
              s.pop();
            if(s.size()==0)
             v.push_back(-1);
            else
            v.push_back(s.top().second);
        }
        s.push({arr[i],i});
      }
    
        for(int i=0;i<n;i++)
          cout<<i-v[i]<<" ";
            
}