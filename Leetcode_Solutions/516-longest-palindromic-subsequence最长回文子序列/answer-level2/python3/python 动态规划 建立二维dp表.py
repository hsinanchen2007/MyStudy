### 解题思路
> 1. 根据题目建立dp表，dp[i...j]表示范围从i到j的最长回文子序列长度
> ![在这里插入图片描述](https://pic.leetcode-cn.com/7276f4427d9cf688cd84f1151bbef607cb72636b0ea4f722ec6a527220444940.png)
> 为了便于找状态转移方程，将最长回文子序列的长度呈现，而且这里有i和j，将一维dp表转为二维，一维为正序s，一维为逆序s，dp[i][j]相当于dp[i...j]表示范围从i到j的最长回文子序列长度。因为i始终小于j，所以左下方的dp[i][j]都为0。
> ![在这里插入图片描述](https://pic.leetcode-cn.com/69bbc2089ffd575080002b1b66cdfb27176ba4015b607b68081d76d670d45789.png)
> 2. 初始化，只有一个字符的最长回文子序列长度为1，即i == j时的dp都为1
![在这里插入图片描述](https://pic.leetcode-cn.com/2a31437589af720dc77ba351b3dccce69e27d6881133de4cb7f4cead5846259b.png)
>3. 数学归纳找规律：
>如果s[i] == s[j] 则在上一个回文子序列长度上dp[i+1][j-1]（即dp[i+1...j-1]）加上两个字符的长度+2。
>如果s[i] != s[j] 则把s[i]和s[j]分别加入s[i+1][j-1]中，即变为s[i][j-1]和s[i+1][j]，看哪一边的回文子序列更长（max）。
![在这里插入图片描述](https://pic.leetcode-cn.com/69368a8e4109c516c13a265c512031fa4a8515a6933d1cb468707e7f5fca8001.png)
> 4. 遍历dp表时
> 对i要反向遍历for i in range(len(s)-1, -1, -1)，
> 对j正向遍历并避开左下方的范围for j in range(i+1, len(s))
>![在这里插入图片描述](https://pic.leetcode-cn.com/1f1b9621169b80afc5b5372c7914454f34c896634e33a28cf170660ee9e13391.png)
> 5. 最后要求的是dp[0][len(s)-1]即dp[0...len(s)-1]的最长回文子序列

### 代码

```python3
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        # <1.创建dp表（初始化）>
        dp = [[0 for i in range(len(s))] for j in range(len(s))]
        for i in range(len(s)):
            dp[i][i] = 1
        
        # <2.循环修改dp表>
        for i in range(len(s)-1, -1, -1): # 对i要反向遍历
            for j in range(i+1, len(s)):  # 对j正向遍历且避开j小于i的情况
            
                # <3.如果相等>则在上一个回文子序列长度上加上两个字符的长度
                if s[j] == s[i]:
                    dp[i][j] = dp[i+1][j-1] + 2
                    
                # <4.如果不相等>则对比哪边的回文子序列更长
                elif s[j] != s[i]:
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j])
        
        return dp[0][len(s)-1] # 返回dp[0...len(s)-1]的最长回文子序列
```