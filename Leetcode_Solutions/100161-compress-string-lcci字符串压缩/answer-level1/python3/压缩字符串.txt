### 解题思路
果然这种题还是比较阴险的，要考虑是否输入为空字符串

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if len(S) == 0:
            return S
        ret, temp, count = S[0], S[0], 1
        for i in S[1:]:
            if i != temp:
                ret += str(count)
                count, temp = 1, i
                ret += str(i)
            else:
                count += 1
        ret += str(count)
        return ret if len(ret) < len(S) else S
```