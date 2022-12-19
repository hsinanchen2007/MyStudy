### 解题思路
前缀代表str[0:length],从0开始
我这里是从最好的情况先考虑的。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        lstrs = len(strs)
        if lstrs == 0:
            return ""

        len_first = len(strs[0])
        i = len_first

        while i >= 1:
            prefix = strs[0][0:i]
            k = 1
            while k < lstrs:
                if strs[k][0:i] != prefix:
                    break
                else:
                    k += 1
            if k == lstrs:
                return prefix
            else:
                i -= 1

        return ""

```
### 理解了一下官方给出的水平法，写了一个python版本。
```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        lstrs = len(strs)
        if lstrs == 0:
            return ""

        len_first = len(strs[0])
        i = len_first
        prefix = strs[0][0:i]

        j = 1
        while j < lstrs:
            while strs[j][0:i] != prefix:
                i -= 1
                if i == 0:
                    return ""
                prefix = strs[0][0:i]
            j += 1
            
        return prefix
```
