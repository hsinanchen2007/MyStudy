### 解题思路

### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<(float)i/2;j++){
                dp[i]+=j==i-j-1?dp[j]*dp[j]:dp[j]*dp[i-j-1]*2;
            }
        }
        return dp[n];
    }
};
```