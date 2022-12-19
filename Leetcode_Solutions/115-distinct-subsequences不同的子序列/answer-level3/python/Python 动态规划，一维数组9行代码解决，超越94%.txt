### 解题思路
动态规划
从左往右模型
先看二维的情况，可以简化为一维数组
1.s[i]!=t[j]，匹配不上，i+= 1直接过
2.若相等：
要么i+=1，j+=1，匹配上了，看后续有几个
要么只是i+=1,继续用后面的匹配
basecase:
只要j匹配完了，返回1，
否则j没匹配完，而i没有了，返回0

### 代码

```python3
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        if s is None or t is None:
            return 0
        dp = [0 for i in range(len(t)+1)] 
        dp[len(t)] = 1
        for i in range(len(s)-1, -1, -1):
            for j in range(0, len(t)):
                if s[i] == t[j]:
                    dp[j] += dp[j+1]
        return dp[0]
        
       
                
        
       
```