# 题解
很自然的想法，模拟真实的杨辉三角填入过程。边界全为1，不为1的位置$dp[i][j]=dp[i-1][j-1]+dp[i-1][j]$
## 模拟法（动态规划）

 1. 初始化结果数组，$numRows$表示结果数组$dp$的行数，每一行的元素个数等于所处第几行。全部初始化为0
 2. 将边界全部初始化为1
 3. 遍历$dp$，将为$0$的位置使用动态规划填入，公式：$dp[i][j]=dp[i-1][j-1]+dp[i-1][j]$

### 复杂度分析
 - 时间复杂度：$O(n^{2})$，等差数列求和。
 - 空间复杂度：$O(n^{2})$，等差数列求和。

### Python

```python
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        dp=[[0]*n for n in range(1,numRows+1)] 
        for i in range(numRows):
            dp[i][0]=dp[i][-1]=1
        for i in range(0,numRows):
            for j in range(i+1):
                if(dp[i][j]==0):
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
        return dp

```
