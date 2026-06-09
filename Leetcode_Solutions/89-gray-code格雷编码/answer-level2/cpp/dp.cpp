### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<vector<int>> dp(n+1);
        vector<int> a;
        a.push_back(0);
        dp[0]=a;
        if(n==0) return dp[0];
        for(int i=1;i<=n;i++){
            dp[i].resize(2*dp[i-1].size());
            for(int j=0;j<dp[i-1].size();j++){
                dp[i][j] = dp[i-1][j];
            }
            for(int j=dp[i-1].size();j<dp[i].size();j++){
                dp[i][j] = pow(2,i-1)+dp[i-1][dp[i-1].size()*2-j-1];
            }
        }

        return dp[n];

    }
};
```