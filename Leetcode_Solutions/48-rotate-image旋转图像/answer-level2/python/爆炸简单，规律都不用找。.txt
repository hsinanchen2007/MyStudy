### 解题思路
首先，shout out to 老铁 [@lucaschen](/u/lucaschen/)
我们的解题思路基本上一样。这个解献给那些和我一样，脑子RAM比较小的，容不下那么多规律的小伙伴。

![Screen Shot 2020-03-22 at 16.41.40.png](https://pic.leetcode-cn.com/1e602b51121645fd4622381eb5330ed08e7e0cfe25bb1e80625a4598b4ef530e-Screen%20Shot%202020-03-22%20at%2016.41.40.png)

根据题目的需求，先将matrix转置， 就是把1，2，3行对调，换成3，2，1
然后从最后一行开始，逐一对调elements

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for x in range(len(matrix)):
            for y in range(x):
                matrix[x], matrix[y] = matrix[y], matrix[x]

        for x in range(len(matrix) - 1, -1, -1):
            for y in range(x):
                matrix[x][y], matrix[y][x] = matrix[y][x], matrix[x][y]
```