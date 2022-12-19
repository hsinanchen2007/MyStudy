### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        m=len(triangle)
        dp=[[0]*m for _ in range(m)]
        # 从底向上
        #[2]
        #[3,4]
        #[6,7,9]
        #  动态规划
        for i in range(m-1,-1,-1):
            # 范围是 每一行 len(triangle[i])
            for j in range(len(triangle[i])):
                #最底一行 直接赋值
                if i==m-1:
                    dp[i][j]=triangle[i][j]
                else:
                    #转移方程
                    dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j]
        return dp[0][0]
```