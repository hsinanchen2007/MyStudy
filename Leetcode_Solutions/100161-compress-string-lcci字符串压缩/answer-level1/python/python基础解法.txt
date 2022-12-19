### 解题思路
遍历字符串，统计出现的次数，将次数加在字符后面，最后比较字符length

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ""
        ch = 0
        chs = S[0]
        ans = ""
        for c in S:
            if c == chs:
                ch += 1
            else:
                ans += chs + str(ch)
                chs = c
                ch = 1
        ans += chs + str(ch)

        return ans if len(ans) < len(S) else S
```