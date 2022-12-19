### 解题思路
写dp的题目最重要的就是：要知道dp数组元素含义，要知道每一个数组元素是由前面的数组元素通过某一个算式（归纳法，概括，找规律得到该算式）得到的。而dp的状态转移方程就是该算式，dp的最优子结构意思一个大问题的最优解可以有他子问题的最优解构成。。（说白了就是这个问题的解可以有你的子问题的解通过某个关系得到）
### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<n;i++) dp[0][i]=1;
        for(int i=0;i<m;i++) dp[i][0]=1;
        dp[0][0]=1;
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        return dp[m-1][n-1];
    }
};
```