设置一个指针，设置一个行数的字符串列表。从前往后遍历字符串，指针不断从0到numRows，再从numRows到0，对每个s[i]赋值给字符串列表。

```python []
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        tem = [""] * numRows
        loc = 0
        flag = True
        for i in range(0, len(s)):
            tem[loc] = tem[loc] + s[i]
            if flag:
                loc = loc + 1
                if loc >= numRows:
                    flag = False
                    loc = loc - 2
            else:
                loc = loc - 1
                if loc < 0:
                    flag = True
                    loc = loc + 2
        res = ""
        for i in range(numRows):
            res = res + tem[i]
        return res
```

