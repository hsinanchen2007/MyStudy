### 解题思路
也许有更好的代码。



### 代码

```python3
class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars)
        i, j = 0, 0
        while j <n:  # 这里用 for j in range(n) 但下面 j 一直在变大怎么办
            val = 1
            while j+1<n and chars[j+1] == chars[j]:
                val += 1
                j += 1
            chars[i] = chars[j]
            i += 1
            if val>1:
                for x in str(int(val)):
                    chars[i] = x
                    i += 1
            j += 1  # 漏了此导致 bug 
        return i 
```