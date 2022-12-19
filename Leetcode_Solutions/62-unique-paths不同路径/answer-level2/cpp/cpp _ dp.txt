### 解题思路
可省略矩阵边界的特殊处理

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(m+1,0);
        dp[1] = 1;
        for(int i = 1;i <= n;++i ){
            for(int j = 1;j <= m;++j){
                    dp[j] = dp[j]+dp[j-1];
            }
        }

        return dp[m];
    }
};
```