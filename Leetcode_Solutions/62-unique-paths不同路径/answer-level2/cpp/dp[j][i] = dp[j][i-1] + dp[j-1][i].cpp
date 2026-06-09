### 解题思路
这道题典型的动态规划，很像斐波那契数列
递推公式为：dp[j][i] = dp[j][i-1] + dp[j-1][i]
(j,i)处的路线种类 = (j,i-1)处的种类+(j-1,i)处的种类

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) return 0;
        vector<int> tmp(m,1);
        vector<vector<int>> dp(n, tmp);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 && j == 0) continue;
                int val1 = i > 0? dp[j][i-1]: 0;
                int val2 = j > 0? dp[j-1][i]: 0;
                dp[j][i] = val1 + val2;
            }
        }
        return dp.back().back();
    }
};
```
### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 58.28% 的用户 
内存消耗 : 6.5 MB , 在所有 C++ 提交中击败了 100.00% 的用户