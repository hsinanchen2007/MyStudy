## 解题思路
### 题目概括

n 个工作，d 天，每天完成一个或多个工作，每日工作量是当日工作量最大的一个工作的值。工作必须顺序执行。

求：d 天完成所有工作最小工作量的和

### 解法

二维数组 dp\[i\]\[j\] 代表使用 i 天完成 j 个工作的最小工作量。（注意 dp 数组的第一列和第一行，也就是下标 0，是没有用的，也没有意义）

#### 状态转移

首先只有 j >= i 的时候才有解，否则返回 -1

所以要求的是 i 天里工作数从 i 到 n。

i 天做 j 个工作。可以是前 i - 1 天做了前 k 个工作，最后一天做了 剩余所有的工作（最后一天的工作量是：k 到 j 的最大值），所以

```python
dp[i][j] = dp[i-1][j-1] + jobDifficulty[j-1] # 初始化成前 i-1 天做了 j-1 个工作，最后一天做最后一个工作
work = jobDifficulty[j-1] # work 是 k 到 j 的最大值
for k in range(j-2, i-2, -1):
    work = max(jobDifficulty[k], work)
    if dp[i-1][k] + work < dp[i][j]: # i-1 天做前 k 个工作，最后一天做 k 到 j 的工作。
        dp[i][j] = dp[i-1][k] + work
```

#### 初始化

初始化 1 天完成 1 个任务，2 个任务 ..... n 个任务。工作量自然就是这些任务中的最大值。

```python
for i in range(2, jc+1):
    dp[1][i] = max(dp[1][i-1], jobDifficulty[i-1])
```




### 代码

```python
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        jc = len(jobDifficulty)
        if d > jc: return -1
        dp = [[-1 for i in range(jc+1)] for i in range(d+1)]
        dp[1][1] = jobDifficulty[0]

        for i in range(2, jc+1):
            dp[1][i] = max(dp[1][i-1], jobDifficulty[i-1])
        
        for i in range(2, d+1):
            for j in range(i, jc+1):
                dp[i][j] = dp[i-1][j-1] + jobDifficulty[j-1]
                work = jobDifficulty[j-1]
                for k in range(j-2, i-2, -1):
                    work = max(jobDifficulty[k], work)
                    if dp[i-1][k] + work < dp[i][j]:
                        dp[i][j] = dp[i-1][k] + work
        return dp[d][jc]
```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)