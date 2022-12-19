### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [[] for i in range(n+1)]
        dp[0].append('')
        dp[1].append('()')
        for i in range(2, n+1): #dp[i] = '('+ dp[p] ')'+dp[q],  p+q = i-1
            for p in range(i):
                for j in dp[p]:
                    for k in dp[i-p-1]:
                        dp[i].append('(' +j+ ')' +k)
        return dp[-1]
```