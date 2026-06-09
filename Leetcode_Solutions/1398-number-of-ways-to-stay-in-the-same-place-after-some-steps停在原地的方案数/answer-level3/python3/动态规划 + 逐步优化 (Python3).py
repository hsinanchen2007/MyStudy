## 分析：动态优化  
**转移矩阵**：dp[i][j]表示花费i步到达位置j的方案总数，则dp[i][j]一共有3个来源（暂时不考虑数组边界，及 j = 0 或 j = arrLen-1时）：

+ 从dp[i-1][j-1]向右移动一步到达
+ 从dp[i-1][j]原位停留一次到达
+ 从dp[i-1][j+1]向左移动一步到达  

则**转移矩阵**可写为：dp[i][j] = dp[i-1][j-1] + dp[i-1][j]  + dp[i-1][j+1]  
**考虑i=0时**：dp[i][j] = dp[i-1][j] +dp[i-1][j+1]  
**考虑i=arrLen-1时**： dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

**数组规模**：
+ 数组dp不一定需要开到steps\*arrLen，若steps<arrLen，i_max到steps即可，所以数组dp定义为steps\*min(steps, arrLen)steps即可
+ 由于题目要求的是dp[steps][0]，所以实际上dp数组右下三角都是不需要计算的，可节省一部分时间（和空间）

**模运算**: 由于 模 运算的分配律，每次运算之后都可先 模 10^9+7 以减小数字大小

### 代码1 （没有优化右下三角）
```
class Solution:
    def numWays(self, steps, arrLen):
        mod = 10**9 + 7
        jMax = min(steps, arrLen)
        dp = [[0]*jMax for i in range(steps+1)]
        dp[0][0] = 1
        for i in range(1, steps+1):
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod
            for j in range(1, len(dp[i])-1):
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % mod
            dp[i][len(dp[i])-1] = (dp[i-1][len(dp[i])-2] + dp[i-1][len(dp[i])-1]) % mod
        return dp[steps][0]
```
### 代码2（优化右下三角，降低空间消耗）  
**由于题目要求的是dp[steps][0]，所以实际上dp数组右下三角都是不需要计算的，可节省一部分时间（和空间）**
```
class Solution:
    def numWays(self, steps, arrLen):
        mod = 10**9 + 7
        jMax = min(steps, arrLen)
        dp = [[0]*min(jMax, steps-i+1) for i in range(steps+1)]
        dp[0][0], dp[1][0], dp[1][1] = 1, 1, 1
        for i in range(2, steps+1):
            for j in range(len(dp[i])):
                if j == 0:
                    dp[i][j] = (dp[i-1][0] + dp[i-1][j+1]) % mod
                elif j == jMax-1:
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod
                else:
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % mod
        return dp[steps][0]
```

### 代码3：追求少代码量的写法
为了减少代码行数，想办法避免上述代码中的if...else...判断，在每行首尾多加一个0，实际运算j取值从1开始到倒数第2个。  
**注：追求代码行数少，会牺牲一定的可读性，不一定可取**
```
class Solution:
    def numWays(self, steps, arrLen):
        dp = [[0]*(min(min(steps, arrLen), steps-i+1)+2) for i in range(steps+1)]
        dp[0][1]= 1
        for i in range(1, steps+1):
            for j in range(1,len(dp[i])-1):
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % (10**9+7)
        return dp[steps][1]
```

### 代码4：进一步压缩空间（同时追求少代码量）  
用两行数组，交替作为 step=i-1 和 step=i 时的dp值，所以dp初始化为  2\*(min(steps, arrLen)+2)  
```
class Solution:
    def numWays(self, steps, arrLen):
        dp = [[0,1] + [0]*min(steps, arrLen) for i in range(2)]
        for i in range(steps):
            for j in range(1, min(min(steps, arrLen), steps-i+1)+1):
                dp[(i+1)%2][j] = (dp[i%2][j-1] + dp[i%2][j] + dp[i%2][j+1]) % (10**9+7)
        return dp[steps%2][1]
```
结果：
![微信截图_20191125022024.png](https://pic.leetcode-cn.com/be387012a1f390b333152ea77511283301eb98b0dc1deaaad786015f83c00fa6-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191125022024.png)




