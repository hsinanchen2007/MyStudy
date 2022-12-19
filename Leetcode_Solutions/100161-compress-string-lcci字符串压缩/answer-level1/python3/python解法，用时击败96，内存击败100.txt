### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ''
        ans = ''
        ch = S[0]
        cnt = 0
        for c in S:
            if c == ch:
                cnt += 1
                continue
            else:
                ans += ch + str(cnt)
                ch = c
                cnt = 1
        ans += ch + str(cnt)    
        return  ans if len(ans) < len(S) else S
```