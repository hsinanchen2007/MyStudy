### 解题思路
一键操作。

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        if not matrix:
            return

        matrix[:] = [list(i) for i in zip(*matrix[::-1])]
```