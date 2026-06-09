### 解题思路
如代码dp[i][j]表示从i刷到j的可用颜色组合种类

### 代码

```cpp
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(); if(n==0) return 0;
        int k = costs[0].size();  if(k==0) return 0;//k中染料
        vector<vector<int>> dp(n,vector<int>(k,INT_MAX));
        dp[0] = costs[0];
        for(int i=1;i<costs.size();i++){
            for(int j=0;j<k;j++){
                for(int m=0;m<k;m++){
                    if(j!=m) dp[i][j] = min(dp[i][j],dp[i-1][m]+costs[i][j]);
                }

            }
        }
        int min_num = INT_MAX;
        for(auto a:dp[n-1]){
            min_num = min(min_num,a);
        }
        return min_num;
    }
};
```