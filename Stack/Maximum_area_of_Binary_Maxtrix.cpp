/*
 Maximum area of Binary Maxtrix
 input arr[] :{{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}}
 
 convert this 2d binary array into 1d array according to row and then treat each row as a new histogram array and perform the operation 
 
output : 8
*/





#include <iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int MAH(vector <int> arr){
    int n = arr.size();
    // nearest smallest index to left
    stack <pair<int, int>> left;
    vector <int> leftIndex;
    int psudeoIndex = -1;
    for(int i=0;i<n;i++)
      {
          if(left.size()==0)
            leftIndex.push_back(psudeoIndex);
        else if(left.size()>0 && left.top().first<arr[i])
            leftIndex.push_back(left.top().second);
        else if(left.size()>0 && left.top().first>=arr[i])
           {
               while(left.size()>0 && left.top().first>=arr[i])
                 left.pop();
                if(left.size()==0)
                leftIndex.push_back(psudeoIndex);
                else
                leftIndex.push_back(left.top().second);
           }
           left.push({arr[i],i});
           
      }   
    //nearest smallest index to right
    stack<pair<int,int>> right;
    vector<int> rightIndex;
    psudeoIndex = n;
    for(int i=n-1;i>=0;i--)
      {
          if(right.size()==0)
           rightIndex.push_back(psudeoIndex);
          else if(right.size()>0 && right.top().first<arr[i])
            rightIndex.push_back(right.top().second);
          else if(right.size()>0 && right.top().first>=arr[i])
            {
                while(right.size()>0 && right.top().first>=arr[i])
                right.pop();
                if(right.size()==0)
                  rightIndex.push_back(psudeoIndex);
                 else
                  rightIndex.push_back(right.top().second);
            }
            right.push({arr[i],i});
      }
      
      reverse(rightIndex.begin(), rightIndex.end());
      
      vector<int> area;
      for(int i=0;i<n;i++)
         area.push_back((rightIndex[i]-leftIndex[i]-1)*arr[i]);
         
         return *max_element(area.begin(),area.end());
}



int main() {
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
         cin>>arr[i][j];
    }
     vector<int> v;
     for(int j=0;j<m;j++)
        v.push_back(arr[0][j]);
    int maxi = MAH(v);
    
    for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==0)
                     v[j]=0;
                else
                    v[j] = v[j] + arr[i][j];
            }
          maxi = std::max(maxi,MAH(v))  ;
        }
        cout<<maxi;
}