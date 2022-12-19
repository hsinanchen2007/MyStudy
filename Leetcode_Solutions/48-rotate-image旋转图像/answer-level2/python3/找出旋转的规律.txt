直接找旋转的规律：

![111.png](https://pic.leetcode-cn.com/c8303e20225488486b428ea7501b8f1f728502bcd0a286ee48d004c9d43da82f-111.png)

外层循环上做圈数上的控制：
> 圈数 < N//2

内层循环做每圈上的旋转:
> j < 每层的宽度-1
> 并且j有一个底数：i

```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        
        for i in range(N // 2):
            for j in range(N - 2 * i - 1):
                j = j + i
                matrix[i][j], matrix[j][N - 1 - i], matrix[N - 1 - i][N - 1 - j], matrix[N - 1 - j][i] =  matrix[N - 1 - j][i], matrix[i][j], matrix[j][N - 1 - i], matrix[N - 1 - i][N - 1 - j]
```
