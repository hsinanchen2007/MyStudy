### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        res = []
        n, i, j = len(S), 0, 0

        while i < n and j < n:
            if S[i] == S[j]:
                j += 1
            else:
                res.append(S[i])
                res.append(str(j - i))
                i = j
            if j == n:
                if S[i] == S[j - 1]:
                    res.append(S[i])
                    res.append(str(j - i))
                else:
                    res.append(S[i])
                    res.append(S[j - 1])
        if len(res) < n:
            return "".join(res)
        else:
            return S
```