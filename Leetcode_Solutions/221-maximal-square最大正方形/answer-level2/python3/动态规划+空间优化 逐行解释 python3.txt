# 题解
## 动态规划
$dp[i][j]$表示以第$i$行，第$j$列处为右下角的最大正方形的边长。
仅当该位置为$1$时，才有可能存在正方形。且递推公式为：
$dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1$。
含义为若当前位置为$1$，则此处可以构成的最大正方形的边长，是其正上方，左侧，和左上界三者共同约束的，且为三者中的最小值加1。

 1. 特判，若$matrix$为空，返回$0$
 2. 初试化$matrix$的行$m$，列$n$，初始化$dp=[[0,\cdots,0],\cdots,[0,\cdots,0]]$，维度为$(m+1)*(n+1)$，这样便于处理。初试化最大边长$res=0$。
 3. 遍历$dp$数组，遍历行$i$，遍历区间$[1,m+1)$：
 	+ 遍历列$j$，遍历区间$[1,n+1)$：
 		+ 若$matrix[i-1][j-1]=="1"$，此时可能存在正方形：
 		$$dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1$$
 		+ 并更新最大边长$res=max(res,dp[i][j])$
 4. 返回面积$res*res$

例：
![在这里插入图片描述](https://pic.leetcode-cn.com/fd106c5190f7819f165448aeac675fd82b136f70b6d5157c49269b107b398213.png)
![在这里插入图片描述](https://pic.leetcode-cn.com/e480c87e92573419c10e0e5625e11b2534248a612d710e73d64cba86969f4b96.png)	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
### 复杂度分析
 - 时间复杂度：$O(m*n)$
 - 空间复杂度：$O(m*n)$

### Python
```python
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if(not matrix):
            return 0
        m=len(matrix)
        n=len(matrix[0])
        res=0
        dp=[[0]*(n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                if(matrix[i-1][j-1]=="1"):
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1
                    res=max(dp[i][j],res)
        return res*res
```

## 动态规划+空间优化
由动态规划的递推公式：
$dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1$。
可以得出当前位置的最大边长仅取决于上一行和左侧最大边长，因此可将空间优化到$O(n)$
借助$pre$来保存当前位置的左侧。
**注意**
$pre$的更新：

 - 同一行时，若当前位置为$0$，需要将$pre$置为0。
 - 换行时，需要置为$0$

具体看代码。

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(m*n)$
 - 空间复杂度：$O(n)$

### Python
```python
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if(not matrix):
            return 0
        m=len(matrix)
        n=len(matrix[0])
        res=0
        pre=0
        dp=[0]*(n+1) 
        for i in range(0,m):
            for j in range(1,n+1):
                tmp=dp[j]
                if(matrix[i][j-1]=="1"):
                    dp[j]=min(pre,dp[j-1],dp[j])+1
                    res=max(dp[j],res)
                else:
                    dp[j]=0
                pre=tmp
            pre=0
        return res*res
```

