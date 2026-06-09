### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        s = list(secret)
        g = list(guess)
        
        count_a = 0
        for i in range(len(s)-1,-1,-1):
            if s[i] == g[i]:
                count_a += 1
                del s[i]
                del g[i]
        
        s_d = {}
        g_d = {}
        for i in range(len(s)):
            s_d[s[i]] = s_d.get(s[i],0) + 1
            g_d[g[i]] = g_d.get(g[i],0) + 1

        count_b = 0
        for k in s_d:
            if k in g_d:
                count_b += min(s_d[k],g_d[k])

        return str(count_a) + "A" + str(count_b) + "B"


```