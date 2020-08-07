/*
 Maximum area of Histogram
 input arr[] :{6,2,5,4,5,1,6}
 step 1:  nearest smallest index to left
   leftIndex :{-1,-1, 1, 1, 3, -1, 5}
step 2:  nearest smallest index to right
   rightIndex : {1, 5,  3, 5, 5, 7, 7}
step 3 : width between left and right 
    widthIndex : {1,5, 1, 3,1, 7,2}
step 4: area array and maximum of area area    
    
output : 12
*/


#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
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
         
         cout<<*max_element(area.begin(),area.end());
      
      
      
      
}