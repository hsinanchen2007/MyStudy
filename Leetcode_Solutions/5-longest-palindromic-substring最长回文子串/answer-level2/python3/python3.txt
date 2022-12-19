### 解题思路
分别判断两种回文类型

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        l, res = [], []
        for i in range(len(s)):
            k, v = i, i
            while k > -1 and v < len(s):
                if s[k] == s[v]:
                    l = s[k:v+1]
                    if len(l) > len(res):
                        res = l
                    k -= 1
                    v += 1
                else:
                    break
            k, v = i, i+1
            while k > -1 and v < len(s):
                if s[k] == s[v]:
                    l = s[k:v+1]
                    if len(l) > len(res):
                        res = l
                    k -= 1
                    v += 1
                else:
                    break
        return res if res else ""        
```