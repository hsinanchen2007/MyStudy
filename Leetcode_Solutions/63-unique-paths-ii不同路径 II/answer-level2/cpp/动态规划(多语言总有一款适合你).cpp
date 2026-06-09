# 思路
这一题是不同路径的一个进阶版，添加了障碍物，同样采用动态规划，我们先列出不考虑障碍物的递推公式：
$$
dp[i][j] = 
\begin{cases}
1 & \text{$(i = 0, j = 0)$}　\\
dp[i][j - 1] & \text{$(i = 0, j \neq 0)$} \\
dp[i - 1][j] & \text{$(i \neq 0, j = 0)$} \\
dp[i - 1][j] + dp[i][j - 1] & \text{$(i \neq 0, j \neq 0)$}
\end{cases}
$$
在考虑障碍物的情况下　　
- 对于第一个式子，仅在该点为障碍物的时候会导致路径为０(也会导致网络中任意一点，路径均为０)
- 对于第二个式子，仅会在该点为障碍物的时候导致路径为０，否则机器人可以左方到达，所以和其左方一点的路径相同
- 对于第三个式子，仅会在该点为障碍物的时候导致路径为０，否则机器人可以上方到达，所以和其上方一点的路径相同
- 对于第四个式子，仅会在该点为障碍物的时候导致路径为０，否则机器人可以从左方或上方到达，因此为这两个方向的路径之和　　
- 具体见代码注释

# 代码

## `cpp`

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m < 1) return 0;
        int n = obstacleGrid[0].size();
        if (n < 1) return 0;
        long dp[m][n];  //　使用int提交出现溢出错误，就改为long
        if (1 == obstacleGrid[0][0]) return 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (0 == i && 0 == j) {     //上面判断过(０,０)为１的情况了，这里必定是没有障碍物，因此路径为１
                    dp[i][j] = 1;
                } else if (0 == i && j != 0) {  //　最上面一行网格，如果该点是障碍物，则这一点必定不可达，否则路径和达到其左侧的路径一样
                    dp[i][j] = (1 == obstacleGrid[i][j] ? 0 : dp[i][j - 1]);
                } else if (0 != i && j == 0) {　//　最左侧一列网格，如果该点是障碍物，则这一点必定不可达，否则路径和达到其上侧的路径一样
                    dp[i][j] = (1 == obstacleGrid[i][j] ? 0 : dp[i - 1][j]);
                } else {    //　对于坐标均不为０的点，仅在该点为障碍物的时候不可达
                    dp[i][j] = (1 == obstacleGrid[i][j] ? 0 : dp[i][j - 1] + dp[i - 1][j]);
                }
            }
        }
        return static_cast<int>(dp[m - 1][n - 1]);
    }
};
```
![image.png](https://pic.leetcode-cn.com/1be443da3da625466e1dfdf79fdacc10babf2777cba81a4d95966d9e1c2a1f2a-image.png)

## `python3`

```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        if m < 1:
            return 0
        n = len(obstacleGrid[0])
        if n < 1:
            return 0
        if 1 == obstacleGrid[0][0]:
            return 0
        dp = [[0]*n for _ in range(m)]  # 外层不能使用*，否则会浅拷贝内层，赋值会带来问题，初始化为０，可以避免额外的赋值
        for i in range(0, m):
            for j in range(0, n):
                if 0 == i and 0 == j:
                    dp[i][j] = 1
                elif 0 == i and 0 != j:
                    if 0 == obstacleGrid[i][j]:
                        dp[i][j] = dp[i][j - 1]
                elif 0 != i and 0 == j:
                    if 0 == obstacleGrid[i][j]:
                        dp[i][j] = dp[i - 1][j]
                else:
                    if 0 == obstacleGrid[i][j]:
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        return dp[-1][-1]
```


## `go`

```go
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    m := len(obstacleGrid)
    if m < 1 {
        return 0
    }
    n := len(obstacleGrid[0])
    if n < 1 {
        return 0
    }
    if 1 == obstacleGrid[0][0] {
        return 0
    }
    dp := make([][]int, m)
    for i := 0; i < m; i++ {
        dp[i] = make([]int, n)    // 这里借用了make会初始化为０的trick
        for j := 0; j < n; j++ {
            if 0 == i && 0 == j {
                dp[i][j] = 1
            } else if 0 == i && 0 != j {
                if 0 == obstacleGrid[i][j] {
                    dp[i][j] = dp[i][j - 1]
                }
            } else if 0 != i && 0 == j {
                if 0 == obstacleGrid[i][j] {
                    dp[i][j] = dp[i - 1][j]
                }
            } else {
                if 0 == obstacleGrid[i][j] {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
                }
            }
        }
    }
    return dp[m - 1][n - 1]
}
```


# 分析
- 时间复杂度，需要进行一遍遍历，因此为$O(m*n)$
- 空间复杂度，需要额外的空间保存`dp`，因此为$O(m*n)$