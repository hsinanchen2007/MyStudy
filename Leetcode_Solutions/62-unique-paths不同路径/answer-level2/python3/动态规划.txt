```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        """
           这题比较简单, 很明显的一个动态规划问题
           令dp[i][j]表示到达位置i,j具有的路径数. 此外题目中有机器人每次只能向下或者向右移动,
           所以dp[i][j] = dp[i-1][j] + dp[i][j-1]
           
           可以很明显看到, 每次计算dp[i][j]只依赖前面两个值, 因此空间复杂度可以进一步优化
           
           边界的定义:
             dp[0][0] = 1
        """
        if n == 0 or m == 0:
            return 0
        if n == 1 or m == 1:
            return 1
        
        # 1. 定义完整的dp数组
        # m >=1 以及 n>=2的情况
        dp = []
        for i in range(n):
            dp.append([0.0 for j in range(m)])
        
        for i in range(n):
            dp[i][0] = 1
        for j in range(m):
            dp[0][j] = 1
        
        for i in range(1, n):
            for j in range(1, m):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
        return dp[n-1][m-1]
                
```
第二种解法核心就是使用两个一维数组, 第一个数组存储横向内容
第二个数组存储纵向内容, 横向数组向下运行, 纵向数组向右移动
     
```
# 2. 定义两个数组 dp_1每次向下一层移动, dp_2每次向下一列移动
        dp_1 = [1 for i in range(m)]
        dp_2 = [1 for i in range(n)]
        i, j = 1, 1
        while i < m and j < n:
            # 更新横向数组
            # 更新第一个元素
            dp_1[i-1] = dp_2[j]
            for s_i in range(i, m):
                dp_1[s_i] = dp_1[s_i] + dp_1[s_i-1]
            dp_2[j] = dp_1[i]
            for s_j in range(j+1, n):
                dp_2[s_j] = dp_2[s_j] + dp_2[s_j-1]
            
            # 各自滑动到下一层
            j += 1
            i += 1

        # return max(dp_2[n-1], dp_1[m-1])
        return max(dp_2[n-1], dp_1[m-1])
```
                