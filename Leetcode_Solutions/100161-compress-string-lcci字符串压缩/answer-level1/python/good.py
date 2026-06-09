### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S: return ''
        ch = S[0]
        res = ''
        cnt = 0
        for c in S:
            if c == ch:
                cnt += 1
            else:
                res += ch + str(cnt)
                ch = c
                cnt = 1
        res += ch + str(cnt)
        return S if len(S) <= len(res) else res
```