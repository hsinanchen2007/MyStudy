### 解题思路
首先需要注意子序列代表有顺序，如果说没有顺序的话可以用第二种方法，要有顺序的话可以用动态规划
dp[i][j]:以下标i为起始点，下标j为结束点的子串的最长回文子序列长度。
当s[i] == s[j]时，dp[i][j] = dp[i+1][j-1] + 2（当i+1>j-1时，dp[i+1][j-1]为0）；
当s[i] != s[j]时，dp[i][j] = max(dp[i+1, j], dp[i, j-1])
初始dp[][] = 0【考虑到dp[i][j]会被用到(i>j)】
因为计算dp[i][j]（i!=j）时，会用到其左下边信息,考虑自下往上逐行计算，每行自左至右计算。
i n-1 to 0:
dp[i][i] = 1
j i+1 to n-1
在计算dp[i][j]（i不等于j）时,只用到其左边、下边和左下边信息。若改用一维数组记录信息，其左边和下边信息在计算时仍保存在数组里，因此，只需用一变量temp记录会发生变化的左下边信息即可（在其变化前）


### 代码

```python
class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """   
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

    def longestPalindrome(s):
        ans = 0
        counter = Counter(s)
        for key in counter.keys():
            v = counter[key]
            ans += v // 2 * 2
            if ans % 2 == 0 and v % 2 == 1:
                ans += 1
        return ans