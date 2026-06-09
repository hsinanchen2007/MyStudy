### 解题思路
和长方形从左上角走到右下角类似，就是根据给出的二维列表构造缓存表，
即从上到下求出每个格子的最小路径和，每个格子和他左&右上方的格子值有关，取最小的值
![捕获1.PNG](https://pic.leetcode-cn.com/043e3680f27c85880c55d2ffd079fe919c10c9eb24105ac61c8e0f01c1029176-%E6%8D%95%E8%8E%B71.PNG)


### 代码

```python3
class Solution:
    # 每个格子最多只能由2个上层的节点移动到达，边际节点只能由一个上层节点移动到达
    # dp[i][j] = triangle[i][j] + min(dp[i-1][j-1],dp[i-1][j])
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # 计算行数
        t = len(triangle)
        dp = [[1]*i for i in range(1,t+1)]
        dp[0][0] = triangle[0][0]
        # 初始化边界节点(从第二行开始)
        for i in range(1,t):
            dp[i][0] = dp[i-1][0] + triangle[i][0]
            dp[i][i] = dp[i-1][i-1] + triangle[i][i]
        # 从第三行开始构建状态转移表
        for i in range(2,t):
            for j in range(1,i):
                dp[i][j] = triangle[i][j] + min(dp[i-1][j-1],dp[i-1][j])
        # 最后寻找出最后一行的最小值即为最小路径和
        minval = dp[-1][-1]
        for i in range(t-1):
            if dp[t-1][i] < minval:
                minval = dp[t-1][i]

        return minval 
```