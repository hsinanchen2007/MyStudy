### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        res = [0] * len(s)
        for i in range(len(s)):
            res[i-n] = s[i]
        
        return ''.join(res)
```