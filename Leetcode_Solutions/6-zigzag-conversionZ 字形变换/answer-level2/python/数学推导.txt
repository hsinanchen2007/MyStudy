对每一行进行计算，算出来每一行当中每一个位置对应的字母即可。

整道题目的代码如下：

```python
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s

        res = ""
        n = len(s)
        for i in range(numRows):
            if i > 0 and i < numRows - 1:
                first = i
                second = i + (numRows - i - 1) * 2
                while first < n:
                    res += s[first]
                    if second < n:
                        res += s[second]
                    first += (2*numRows - 2)
                    second += (2*numRows - 2)
            else:
                index = i
                while index < n:
                    res += s[index]
                    index += (2*numRows - 2)

        return res
```

