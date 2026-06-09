### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[1]!=b[1]) return a[1]>b[1];
        else return a[0]>b[0];
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
         vector<vector<int>> ans;
         vector<int> res;
         int N=restaurants.size();
         int M=restaurants[0].size();
         for(int i=0;i<N;i++)
         {
            if(veganFriendly==1)
            {
                if(restaurants[i][2]==1)
                {
                    if(restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance)
                    {
                        ans.push_back(restaurants[i]);
                    }
                    else continue;
                }
                else continue;
            }
            else
            {
                if(restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance)
                {
                    ans.push_back(restaurants[i]);
                }
                else continue;
            }
         }
         sort(ans.begin(),ans.end(),cmp);
         for(auto e:ans) res.push_back(e[0]);
         return res;
    }
};
```