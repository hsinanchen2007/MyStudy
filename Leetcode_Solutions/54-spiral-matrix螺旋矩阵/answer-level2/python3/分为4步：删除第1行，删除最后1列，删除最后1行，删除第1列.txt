### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        res = []
        while matrix:
            # 删除第1行
            if matrix:
                res += matrix[0]
                matrix.pop(0)
            else:
                break
            # 删除最后1列
            if matrix:
                n = len(matrix)
                flag = 0
                for i in range(n):
                    elemnt = matrix[i-flag].pop()
                    res.append(elemnt)
                    if not matrix[i-flag]:
                        matrix.pop(i-flag)
                        flag += 1
            else:
                break
            # 删除最后1行
            if matrix:
                matrix[-1].reverse()
                res += matrix[-1]
                matrix.pop(-1)
            else:
                break
            # 删除第1列
            if matrix:
                n = len(matrix)
                flag = 0
                for i in range(-1, -n, -1):
                    elemnt = matrix[i+flag].pop(0)
                    res.append(elemnt)
                    if not matrix[i+flag]:
                        matrix.pop(i+flag)
                        flag += 1
            else:
                break
        return res
```