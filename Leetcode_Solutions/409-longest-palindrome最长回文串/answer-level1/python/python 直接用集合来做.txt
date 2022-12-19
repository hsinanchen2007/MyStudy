想法很简单，就是最终看有多少个奇数个数的字母。

```python
class Solution(object):
    def longestPalindrome(self, s):
        odd = set()
        even = set()
        for i in s:
            if (i not in odd) and (i not in even):
                odd.add(i)
            elif i in odd:
                odd.remove(i)
                even.add(i)
            else:
                even.remove(i)
                odd.add(i)
        if not odd:
            return len(s)
        return len(s) - (len(odd) - 1)
```