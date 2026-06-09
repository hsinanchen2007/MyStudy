### 解题思路
- 给转换后的每行建立一个字符串容器
- 遍历每个字符串，确定其转换后的行号，放入容器
- 小于numRows,行号递增，大于numRows,行号递减

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        """将一个字符串变换为Z型"""
        if not s:
            return ""
        if numRows < 2:
            return s
        convert_list = [""] * numRows
        l, flag = 0, -1
        for i in s:
            convert_list[l] += i
            if l == 0 or l == numRows -1:
                flag *= -1
            l += flag

        return "".join(convert_list)
```