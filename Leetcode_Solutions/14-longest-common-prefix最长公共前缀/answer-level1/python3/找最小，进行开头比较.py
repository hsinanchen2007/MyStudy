### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def longestCommonPrefix(self, strs):
        if strs == []:
            return ""
        d = strs[0]
        for i in strs:
            if len(d) > len(i):
                d = i
        a = len(d)
        i = 0
        b = d[:i+1]
        while i < a:
            b = d[:i+1]
            for c in strs:
                if c.startswith(b):
                    e = 1
                else:
                    e = 0
                    b = d[:i]
                    break
            if e == 0:
                break
            i += 1
        return b

```