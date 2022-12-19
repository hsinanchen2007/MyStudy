### 解题思路
将每行的字母分别储存下来
在哪一列不重要，因此和形状无关，每一个相邻的字符都在不同行（行数大于一）

创建一个二维数组row_list，记录每一行的字符
遍历字符串，从row_list[0]开始储存，每遍历一个字符就换一行
op记录下一个字符记录在当前行的上一行还是当前行的下一行
最后将二维数组转化成字符串输出

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if not s or numRows == 1:
            return s
        
        row_list = [[] for _ in range(numRows)]
        row_i = 0
        for char in s:
            if row_i == 0:
                op = 1
            elif row_i == numRows - 1:
                op = -1
            row_list[row_i].append(char)
            row_i = row_i + op
        
        res = ''
        for i in range(numRows):
            res += ''.join(row_list[i])
        return res
```