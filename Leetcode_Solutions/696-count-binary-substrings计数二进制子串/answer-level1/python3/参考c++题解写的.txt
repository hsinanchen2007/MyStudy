### 解题思路
c++题解思路，很有道理
### 代码

```python3
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        n, pre, cur, len_ = 0, 0, 1, len(s) - 1
        for i in range(0, len_):
            if s[i] == s[i + 1]:
                cur += 1
            else:
                pre = cur
                cur = 1
            if pre >= cur:
                n += 1
        return n
```