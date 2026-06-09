### 解题思路
首先排除特殊情况，接下来逐个对比hay中字符与needle首字符，相同的情况下再进一步判断。

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        lh = len(haystack)
        ln = len(needle)
        
        if ln == 0:
            return 0
        if lh == 0 or lh < ln:
            return -1
        i = 0
        while(i<=lh-ln):
            if haystack[i] == needle[0]:
                if haystack[i:i+ln] == needle:
                    return i
                else:
                    i = i+1
            else:
                i += 1
        return -1

```