![运行效果.png](https://pic.leetcode-cn.com/b457e599e63705e283ee531dbeba7b4b0240a83a5e5e9eb75727b23982ebc2d3-%E8%BF%90%E8%A1%8C%E6%95%88%E6%9E%9C.png)
一 算法设计
1 确定状态
  dp[i][j]:以下标i为起始点，下标j为结束点的子串的最长回文子序列长度。
2 状态转移方程
  当s[i] == s[j]时，dp[i][j] = dp[i+1][j-1] + 2（当i+1>j-1时，dp[i+1][j-1]为0）；
  当s[i] != s[j]时，dp[i][j] = max(dp[i+1, j], dp[i, j-1])
3 算法流程
初始dp[*][*] = 0【考虑到dp[i][j]会被用到(i>j)】
	如图，因为计算dp[i][j]（i!=j）时，会用到其左下边信息,考虑自下往上逐行计算，每行自左至右计算。
	i n-1 to 0:
		dp[i][i] = 1
		j i+1 to n-1:
			#根据状态方程计算
	return dp[0][n-1]
![算法流程.png](https://pic.leetcode-cn.com/c5c8c7cda85019cfa471d3f58328b55e644b0bff8e16b212c9900cb7a1b0b6df-%E7%AE%97%E6%B3%95%E6%B5%81%E7%A8%8B.png)
4 空间压缩，变二维空间复杂度为一维
  在计算dp[i][j]（i不等于j）时,只用到其左边、下边和左下边信息。若改用一维数组记录信息，其左边和下边信息在计算时仍保存在数组里，因此，只需用一变量temp记录会发生变化的左下边信息即可（在其变化前）。
如此，状态转移方程变为：
s[i] == s[j]: dp[j] = temp + 2
s[i] != s[j]: dp[j] = max(dp[j], dp[j-1])
5 特殊情况处理，提升速度
  当字符串为空字符串或长度为1的字符串时，其最长回文子序列长度为其自身长度。当字符串为回文字符串时，其最长回文子序列长度同样为其自身长度。
二 python3实现及运行效果
```
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:      
        n = len(s)
  
        # special case, give answer directly to save time
        if n <= 1 or s[::-1] == s:
            return n
        
        dp = [0]*n
        for i in range(n-1, -1, -1):
            #temp = dp[i]
            temp = 0  # dp[i] must be 0, so I use 0 instead of dp[i]
            dp[i] = 1            
            for j in range(i+1, n):
                if s[i] == s[j]:
                    #aa = dp[j]                    
                    #dp[j] = temp + 2
                    #temp = aa
                    temp, dp[j] = dp[j], temp + 2
                else:
                    temp = dp[j]
                    if dp[j-1] > dp[j]:
                        dp[j] = dp[j-1]
        return dp[-1]
```
三 复杂度分析
  两层循环，时间复杂度O(N**2)；空间复杂度O(N)。




