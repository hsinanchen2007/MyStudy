从左到右迭代字符串，将每个字符添加到对应的行里。
设置一个计数器counter和方向量d，counter可以确定是否到最顶部行或者最底部行，d则是控制行的增减。
```python []
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if (numRows == 1):
            return s
        l = [""] * numRows
        row = 0
        counter = 0
        d = 1
        for i in range(len(s)):
            l[row] = l[row] + s[i]
            if counter == numRows - 1:
                counter = 0
                d = d * (-1)
            counter = counter + 1
            row = row + d
        result = ''.join(l)
        return result
            
```
