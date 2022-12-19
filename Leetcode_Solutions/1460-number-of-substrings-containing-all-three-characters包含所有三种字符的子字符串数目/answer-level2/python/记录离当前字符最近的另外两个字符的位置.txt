时间复杂度O(n)。


```python
class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {'a': -1, 'b': -1, 'c': -1}  # 记录离当前字符最近的另外两个字符的位置
        res = 0
        for i in range(len(s)):
            # 找到，另外最近的另外两个字符最左边的一个
            if s[i] == 'a':
                mx = min(d['b'], d['c'])
            elif s[i] == 'b':
                mx = min(d['a'], d['c'])
            else:
                mx = min(d['a'], d['b'])
            if mx != -1:
                res += mx + 1   # 直接加上
            d[s[i]] = i
        return res
```
