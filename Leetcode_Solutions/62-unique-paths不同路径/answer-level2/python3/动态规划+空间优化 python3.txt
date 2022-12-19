# 题解
## 动态规划
如图所示，显然边界网格上的路径数为1,。
对于网格$(i,j)$处的路径数，其中$0<i<m$,$0<j<n$。等于网格$(i-1,j)$和网格$(i,j-1)$处的路径之和。
![在这里插入图片描述](https://pic.leetcode-cn.com/1b41f18fcbbfb8c17d26d50e725b8f84ef5bb45774c9b23650eeabc46a2c1f92.png)
 1. 初始化动态数组$dp$，$dp$为$m*n$维数组，第一行和第一列初始化为$1$，其余位置初始化为$0$
 2. 按行遍历，遍历区间$[1,m)$:
 	* 遍历每一列，遍历区间$[1,n)$：
 		+ 网格$(i,j)$处的路径数等于网格$(i-1,j)$和网格$(i,j-1)$处的路径之和，即$dp[i][j]=dp[i-1][j]+dp[i][j-1]$
 
 3. 返回右下角的路径数，$dp[-1][-1]$。

### 复杂度分析
 - 时间复杂度：$O(M*N)$
 - 空间复杂度：$O(M*N)$，借助$dp$数组保存结果

### Python

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp=[[1]*n]+[[1]+[0]*(n-1) for _ in range(m-1)]
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=dp[i-1][j]+dp[i][j-1]
        return dp[-1][-1]
```
### 优化1
仅借助上一行的结果和当前行的结果进行计算
```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        pre=[1]*n
        cur=[1]*n
        for i in range(1,m):
            for j in range(1,n):
                cur[j]=cur[j-1]+pre[j]
            pre=cur[:]
        return cur[-1]
```
### 复杂度分析
 - 时间复杂度：$O(M*N)$
 - 空间复杂度：$O(N)$
### 优化2
仅借助当前行进行计算
```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        cur=[1]*n
        for i in range(1,m):
            for j in range(1,n):
                cur[j]+=cur[j-1]
        return cur[-1]
```
### 复杂度分析
 - 时间复杂度：$O(M*N)$
 - 空间复杂度：$O(N)$ 