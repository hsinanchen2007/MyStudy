### 解题思路
通过保存上一个字符和下标来合并相同的字符

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S or len(S) <= 2:
            return S
        last_char, last_index = S[0], 0
        S = '%s?' % S
        res = []
        for i, c in enumerate(S[1:]):
            if c != last_char:
                res.append(last_char + str(i - last_index + 1))
                last_index, last_char = i + 1, c
        SC = "".join(res)
        return SC if len(SC) < len(S) - 1 else S[:-1]
```