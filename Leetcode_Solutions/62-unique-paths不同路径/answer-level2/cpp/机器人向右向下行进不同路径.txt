### 解题思路
动态规划的思想要“深入人心”，划分最小子问题对应的初始状态，提取状态方程。
最小子问题：单行、单列只有一种路径
对应的初始条件：dp[i][最后一列]=1, dp[最后一行][j]=1;
状态方程：dp[i][j]=dp[i+1][j]+dp[i][j+1];

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1 || n>100 || n<1) return 0;
        int dp[m][n];
        for(int i=0; i<m; i++){
            dp[i][n-1]=1;
        }
        for(int j=0; j<n; j++){
            dp[m-1][j]=1;
        }
        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
```