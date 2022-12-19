### 解题思路
矩阵顺时针旋转常用套路，zip(*)选出列表中各个元组（或列表）的对应位置的元素重新组合成一个元组，map将每个元组转成列表

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix[:] = map(list,zip(*matrix[::-1]))
```