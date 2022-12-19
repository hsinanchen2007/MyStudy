# 题解
本题的难点，将其转化为$0-1$背包问题。
对于给定的数组中的每一个物品重量（元素），选或者不选，使其能够装满容量为$target//2$的背包。
$dp[i][j]$表示在前$i$个物品（元素）选或者不选可以装满容量$j$的背包。
可得递推公式：
$dp[i][j]=\begin{array}{ll}{dp[i-1][j]} & {选择装i} \\ or \\{dp[i-1][j-nums[i]]} & {不装i}\end{array}$
解释：$dp[i][j]$能否被装满，取决于到上一个物品为止是否已经装满$j$或到上一个物品为止是否已经装满$j-nums[i]$

## 动态规划

 1. 特判，若$target$为奇数，返回$False$
 2. 令$target=target//2$
 3. 初始化$dp=[[False,\cdots,False],\cdots,[False,\cdots,False]]$，维度为$n*(target+1)$
 4. 初试化第一行，$dp[0][0]=True$，遍历第一行，将第一个物品可以装满的容量置为$True$
 5. 遍历物品$i$，遍历区间$[1,n)$：
 	+ 遍历所有的容量$j$，遍历区间$[0,target+1)$：
 		+ 若容量$j>=nums[i]$，表示容量大于当前物品的重量：此时，$dp[i][j]=dp[i-1][j]\ or\ dp[i-1][j-nums[i]]$
 		+ 否则：$dp[i][j]=dp[i-1][j]$，因为不可能存在将当前物品装进背包的情况。
 
 6. 返回$dp[n-1][target]$

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(n*(target/2))$
 - 空间复杂度：$O(n*(target/2))$

### Python
```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n=len(nums)
        target=sum(nums)
        if(target%2!=0):
            return False
        target//=2
        dp=[[False]*(target+1) for _ in range(n)]
        dp[0][0]=True
        for i in range(1,target+1):
            if(nums[0]==i):
                dp[0][i]=True
                break
        for i in range(1,n):
            for j in range(target+1):
                if(j>=nums[i]):
                    dp[i][j]=dp[i-1][j] or (dp[i-1][j-nums[i]])
                else:
                    dp[i][j]=dp[i-1][j]
        return dp[-1][-1]
```


## 动态规划+空间优化
我们注意到$dp[i][j]$仅依赖于$dp[i-1]$，由此可将空间优化到$O(target)$

 1. 特判，若$target$为奇数，返回$False$
 2. 令$target=target//2$
 3. 初始化$pre=[False,\cdots,False]$，维度为$target+1$，表示到上一个物品为止的装包情况。初始化$cur=[False,\cdots,False]$，维度为$target+1$，表述当前物品的装包情况
 4. 初试化$pre$，$pre[0]=True$，遍历$pre$，将第一个物品可以装满的容量置为$True$
 5. 遍历物品$i$，遍历区间$[1,n)$：
 	+ 遍历所有的容量$j$，遍历区间$[0,target+1)$：
 		+ 若容量$j>=nums[i]$，表示容量大于当前物品的重量：此时，$cur[j]=pre[j]\ or\ pre[j-nums[i]]$
 		+ 否则：$cur[j]=pre[j]$，因为不可能存在将当前物品装进背包的情况。
 
 6. 返回$cur[target]$

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(n*(target/2))$
 - 空间复杂度：$O(target/2)$

### Python
```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n=len(nums)
        target=sum(nums)
        if(target%2!=0):
            return False
        target//=2
        pre=[False]*(target+1)
        cur=[False]*(target+1)
        pre[0]=True
        for i in range(1,target+1):
            if(nums[0]==i):
                pre[i]=True
                break
        for i in range(1,n):
            for j in range(target+1):
                if(j>=nums[i]):
                    cur[j]= pre[j] or (pre[j-nums[i]])
                else:
                    cur[j]=pre[j]
            pre=cur[:]
        return cur[-1]
```
