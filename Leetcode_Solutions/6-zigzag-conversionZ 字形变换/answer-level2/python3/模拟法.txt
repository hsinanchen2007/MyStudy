### 解题思路
模拟法，[抄袭]
flag 是关键
60 ms, 击败了76.31%
13.3 MB, 击败了58.96%
### 代码

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if not s or numRows < 2: return s

        res = ["" for _ in range(numRows)]  # 存放numRows 行字符串
        i, flag = 0, -1   # i代表行数， flag用于行数变换
        for item in s:  # 迭代字符串s
            res[i] += item  # 按行添加
            # 当遍历到最后一行时，向上或者向下遍历
            if i == 0 or numRows - (i+1) == 0:
                flag = -flag
            i += flag
        return "".join(res)
```