# 思路
机器人只能向下或者向右移动一步，那么对于任意的`i, j`机器人只能从左侧或上方移动过来，特别的对于上边界或左边界，机器人只有一种移动方式。那么就有下面公式：  
$$
dp[i][j] = 
\begin{cases}
1 & \text{$(i = 0, j = 0)$} \\
dp[i][j - 1] & \text{$(i = 0, j \neq 0)$} \\
dp[i - 1][j] & \text{$(i \neq 0, j = 0)$} \\
dp[i - 1][j] + dp[i][j - 1] & \text{$(i \neq 0, j \neq 0)$}
\end{cases}
$$
在该题中可以简化为下式：
$$
dp[i][j] = 
\begin{cases}
1 & \text{$(i = 0 或 j = 0)$} \\
dp[i - 1][j] + dp[i][j - 1] & \text{$(i \neq 0, j \neq 0)$}
\end{cases}
$$

# 代码

## `cpp`
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (0 == m || 0 == n) return 1;
        vector<vector<int>> dp(m, vector<int>(n));　　//　或者int dp[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (0 == i || 0 == j) dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
```
![image.png](https://pic.leetcode-cn.com/ba9aecd6f5f7816bd9e4f23ce005c79baf29b5c43e6ea9945065ddaecb18558f-image.png)


## `python3`
```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # 初始化为１，避免多余的赋值，外层不使用*，否则浅拷贝内层可能会在赋值时候出现问题
        dp = [[1]*n for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
        
        return dp[-1][-1]
```

## `go`
```go
func uniquePaths(m int, n int) int {
	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
		for j := 0; j < n; j++ {
			if 0 == i || 0 == j {
				dp[i][j] = 1
			} else {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
			}
		}
	}
	return dp[m - 1][n - 1]
}
```

# 分析
- 时间复杂度：需要遍历整个矩阵，所以为$O(m*n)$
- 空间复杂度：需要保存dp，所以为$O(m*n)$