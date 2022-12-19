
### 代码

```python3
class Solution:
    def compress(self, chars: List[str]) -> int:
        i = 0
        j = 0
        c = 0
        while j < len(chars):
            if chars[i] == chars[j]:
                j += 1
                c += 1
            if j == len(chars) or chars[i] != chars[j] :
                if j - i > 1:
                    n = i
                    for m in range(len(str(j-i))):
                        chars[n+1] = str(j-i)[m]
                        n += 1
                    for k in range(n+1, j):
                        chars[k] = ""
                i = j
        while "" in chars:
            chars.remove("")
        return len(chars)

```