### 解题思路
- 注意：第1行算作第0个元素；
- 在结果集里产生k + 1个元素，每一个元素都是列表，列表里存放着与行数相对应的0；
- 将每一行的首个元素与最后一个元素置为1；
- 从第3行开始（序号为2），每行产生从第1个到倒数第1个元素，该元素为上一行两个元素之和；
- 返回结果集最后一个元素即为所求；

### 代码

```python3
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [[0] * i for i in range(1, rowIndex + 2)]
        for i in range(rowIndex + 1):
            res[i][0] = 1
            res[i][-1] = 1
        for i in range(2, rowIndex + 1):
             for j in range(1, i):
                 res[i][j] = res[i - 1][j - 1] + res[i - 1][j]
        return res[-1]
```