```python
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n, r = len(matrix), len(matrix) and len(matrix[0]), []
        for l in range(m + n - 1):
            temp = [matrix[i][l - i] for i in range(max(0, l+1 - n), min(l+1, m))]
            r += temp if l % 2 else temp[::-1]
        return r
```
- 0 and 0 答案是 0，此处避免 matrix 为 [] 时导致报错
- 按照从右上角到左下角的顺序遍历 matrix 的所有对角线并放入列表 temp
- 如果 对角线元素个数 是偶数则应该把 temp 反转
- 把 temp 加入结果 r