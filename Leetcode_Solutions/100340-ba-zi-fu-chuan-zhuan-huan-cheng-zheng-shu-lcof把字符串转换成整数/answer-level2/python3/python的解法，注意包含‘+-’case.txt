### 解题思路


### 代码

```python3
class Solution:
    def strToInt(self, str: str) -> int:
        INT_MAX = 2 ** 31 -1
        INT_MIN = -1 * 2 ** 31
        lookup1 = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
        lookup2 = {'+', '-'}
        s = str.lstrip()
        if not len(s):  return 0
        if s[0] in lookup1:
            for i in range(len(s)):
                if s[i] not in lookup1:
                    res =  int(s[:i])
                    break
            else:   res = int(s)
        
        elif len(s) < 2:    return 0

        elif s[0] in lookup2 and s[1] in lookup1:
            for j in range(1, len(s)):
                if s[j] not in lookup1:
                    res =  int(s[:j])
                    break
            else:   res = int(s)
        else:
            return 0
        if res < INT_MIN:   return INT_MIN
        if res > INT_MAX:   return INT_MAX
        return res
```