### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/dafd188bfd8db94030fa3862d2fbf065d5b76c76b8df3fa4cad49fb5381b4107-image.png)


### 代码

```cpp
class Solution {
public:

    int minCost(vector<vector<int>>& costs) {
        int m = costs.size(); if(m==0) return 0;
        vector<vector<int>> dp(m+1,vector<int>(3,0));
        for(int i=1;i<=m;i++){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + costs[i-1][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + costs[i-1][1];
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + costs[i-1][2];
        }
        return min(dp[m][0],min(dp[m][1],dp[m][2]));        
    }
};
```