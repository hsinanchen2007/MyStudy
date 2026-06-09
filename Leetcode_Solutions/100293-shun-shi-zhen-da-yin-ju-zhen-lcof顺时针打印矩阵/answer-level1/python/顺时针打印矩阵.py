### 解题思路
作者 **小码农** 思路，非常简洁易懂

### 代码

```python
class Solution:
    def spiralOrder(self, matrix):
        res = []
        while matrix:
            res += matrix.pop(0) #去掉第一行 将剩下矩阵逆时针旋转成为新矩阵
            matrix = list(zip(*matrix))[::-1]#利用*将元组转化为列表
        return res
```