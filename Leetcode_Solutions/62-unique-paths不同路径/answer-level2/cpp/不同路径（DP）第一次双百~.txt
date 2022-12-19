### 解题思路
![image.png](https://pic.leetcode-cn.com/549b9eccda8a00ed1e35ddc25a997c48b19273556d620edcc315c50e1bcd0f97-image.png)

- 动态规划
- 建立一个二维数组dp[][]，dp[i][j]代表走到第i行第j列这个格子有多少种方法。
- 由于题目要求只能向右或向下走，所以第一行和第一列的每一格都只有一种路径到达，故dp[0][j]这一行和dp[i][0]这一列值都是1。
- 对于任意的大于0的(i，j)，每一格都有两种方法到达：
    - 从(i - 1, j)向下走一步到达；
    - 从(i, j - 1)向右走一步到达；
- 因此，状态转移方程为： dp[i][j] = dp[i][j - 1] + dp[i - 1][j]；
- 最后输出dp[n - 1][m - 1]即可。

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
```