### 解题思路

中间过程是迭代器，勉强符合空间要求吧。

```python []
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix[: ] = zip(*matrix)
        for mat in matrix:
            mat.reverse()
```

用`reversed(matrix)`和`matris[::-1]`还是有区别的，前者是迭代器，没有额外空间，后者会产生$O(N)$的临时空间，尽管在使用后会被销毁

```python []
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix[: ] = zip(*reversed(matrix))
```
