### 解题思路
思路：
第一种解法可用暴力，以左上角为正方形的起始点，然后不断地扩大边长，当不能扩大的时候，更新已经获取的最大的值，然后右移动一格，以最大值+1的边长再去尝试。

既然想到了左上角，为啥不想想右下角？这个时候就突然发现，可以选一个2x2的矩形A，每个矩形都是一个正方形的右下角，元素的值是以这个格子为正方形右下角的时候，最大的边长，你就会发现这个矩形A的右下角的那个正方形的边长其实的依赖于其他三个元素的，如果A[1][1]在matrix里面的值是1，那么这个格子的最大边长就是其他A三个格子里面最小值+1. 如果是A[1][1]在matrix里面的值是0，那么A[0][0]就肯定是0。
这样的话，dp式子就出来了dp[i][j] = min(dp[i-1][j], dp[i][j-1]m dp[i-1][j-1]) + 1. dp[i][j]表示以i，j这个格子为正方形右下角的时，正方形的最大边长。

### 代码

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        long R = matrix.size();
        if (R == 0) {
            return 0;
        }
        long C = matrix[0].size();
        int prev = 0, res = 0;
        vector<int> dp(C+1, 0);
        for (int i=1; i<=R; i++) {
            for (int j=1; j<=C; j++) {
                int temp = dp[j];
                if (matrix[i-1][j-1] == '0') {
                    dp[j] = 0;
                } else {
                    dp[j] = min(prev, min(dp[j], dp[j-1])) + 1;
                    res = max(res, dp[j]);
                }
                prev = temp;
            }
        }
        return res*res;
    }
};
```