### 解题思路
此处撰写解题思路
1、特殊情况numRows=1，直接返回输入数组
2、定义新字符串，计算输入字符串的长度，计算最大间隔max_gap = (numRows - 1)<<1
3、根据指定行数，逐行插入字符，每次插入字符后，改变其间隔
### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        ret_s = ""
        length = len(s)
        max_gap = (numRows - 1)<<1

        for i in range(numRows):
            idx = i
            gap = (numRows - i - 1)<<1
            if gap == 0:
                gap = max_gap

            while idx < length:
                ret_s += s[idx]
                idx += gap
                if gap != max_gap:
                    gap = max_gap - gap
        return ret_s
```