### 解题思路
动态规划： 从底到顶

初始化：终点相邻边界只有一种方式到达
状态转化： dp[i][j] = dp[i+1][j] + dp[i][j+1]; （计数所以相加）

执行结果： 通过
执行用时 : 0 ms , 在所有 cpp 提交中击败了 100.00% 的用户
内存消耗 : 8 MB , 在所有 cpp 提交中击败了 97.24% 的用户

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        int dp[m][n];
        for (int i = 0; i < n-2; i++){
            dp[m-1][i] = 1;
        }
        for (int i = 0; i < m-2; i++){
            dp[i][n-1] = 1;
        }
        for (int i = m-2; i >= 0; i--){
            for (int j = n-2; j >= 0; j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
```