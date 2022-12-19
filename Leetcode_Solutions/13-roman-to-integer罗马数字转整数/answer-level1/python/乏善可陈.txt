判断当前字符是否比后一个字符小，如果是这样，那么它应该取负。

整道题目的代码如下：

```python
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0

        map = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        res = 0
        for i in range(len(s) - 1):
            a = map[s[i]]
            b = map[s[i + 1]]
            if a < b:
                res -= a
            else:
                res += a

        res += map[s[-1]]
        return res
```

