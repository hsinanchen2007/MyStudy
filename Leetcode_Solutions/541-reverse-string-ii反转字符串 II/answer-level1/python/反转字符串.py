### 解题思路
反转字符串，应该有更简洁的方法

### 代码

```python3
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        ret = ''
        while s:
            if len(s) // (2 * k) > 0:
                temp = s[:k]
                ret = ret + temp[::-1] + s[k:2 * k]
                s = s[2 * k:]
            elif len(s) // k > 0:
                temp = s[:k]
                ret = ret + temp[::-1] + s[k:]
                s = []
            else:
                ret = ret + s[::-1]
                s = []
        return ret
```