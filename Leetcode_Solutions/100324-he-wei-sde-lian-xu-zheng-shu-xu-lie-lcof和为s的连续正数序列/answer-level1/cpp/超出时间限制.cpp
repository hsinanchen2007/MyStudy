### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) 
    {
         vector<vector<int>> ans;
         vector<int> p;
         for(int i=1;i<=((target-1)/2);i++)
         {
            int  sum=0;
             for(int j=i;j<target;j++)
             {
                sum+=j;
                if(sum>target)//一开始没写这条判断导致运行数目较大时超出运行时限
                {
                    break;
                } 
                if(sum==target)
                {
                  p.clear();
                  for(int k=i;k<=j;k++)
                  {
                      p.emplace_back(k);
                  }  
                  ans.emplace_back(p);
                  break;
                }
             }
         }
         return ans;
    }
};
```