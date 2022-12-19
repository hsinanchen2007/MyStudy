### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
      vector<vector<int>> res;
      sort(arr.begin(),arr.end());
      int diff=arr[1]-arr[0];
     
      for(int i=1;i<arr.size()-1;i++)
      {
         diff=min(diff,arr[i+1]-arr[i]);
      } 
      
      for(int k=0;k<arr.size()-1;k++)
      {
          vector<int> temp(2,0);
          int tp=arr[k+1]-arr[k];
          if(tp==diff)
          {
              res.push_back({arr[k],arr[k+1]});
          }
      }  
      return res;
    }
};

```