zip用的不熟，老老实实交换元素吧，内存消耗100.00%

```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # 第一步先将行顺序逆序
        i = 0
        j = len(matrix) - 1
        while i < j:
            matrix[i], matrix[j] = matrix[j], matrix[i]
            i += 1
            j -= 1
        # 第二步(x,y)与(y,x)互换，只需操作右上角的元素
        for x, row in enumerate(matrix):
            for y, e in enumerate(row):
                if x > y:
                    matrix[x][y], matrix[y][x] = matrix[y][x], matrix[x][y]
```
![image.png](https://pic.leetcode-cn.com/cf44d1c6037cc3278e9851eb689e8bc86c5dfaf7f302bb9012f7ee1615acfd64-image.png)
