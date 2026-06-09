方法1
维护一个二维的前缀和dp[i][j]表示左上角(0, 0) 右下角(i, j)的矩形区域的所有元素和，可以动态规划O(N^2)求出来, update时候需要更新所有i>=row and j>=col 位置的dp[i][j],
sumRegion求矩形中累加和时候就用套路方式用大小矩形的累加和差值来求解，这样解法update需要更新一大片数值，速度慢



![image.png](https://pic.leetcode-cn.com/4eff16af6eb07ee59c283eed24d387023b49d17aa82071ed361c9bb6cf8b1012-image.png)

```

'''
暴力维护二维的前缀和
update的时候更新量大，速度比较慢
'''

from typing import List

class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.valid = True

        if len(matrix) == 0 or len(matrix[0]) == 0:
            self.valid = False
            return

        self.m = len(matrix)
        self.n = len(matrix[0])
        self.dp = [[0 for _ in range(self.n)] for _ in range(self.m)]
        self.data = matrix

        # dp计算累加和
        for i in range(self.m):
            if i == 0:
                self.dp[0][0] = matrix[0][0]
                for j in range(1, self.n):
                    self.dp[0][j] = matrix[0][j] + self.dp[0][j-1]
            else:
                self.dp[i][0] = self.dp[i-1][0] + matrix[i][0]
                for j in range(1, self.n):
                    self.dp[i][j] = self.dp[i-1][j] + self.dp[i][j-1] - self.dp[i-1][j-1] + matrix[i][j]

    def update(self, row: int, col: int, val: int) -> None:
        if not self.valid:
            return

        sub = val - self.data[row][col]
        self.data[row][col] = val
        for i in range(row, self.m):
            for j in range(col, self.n):
                self.dp[i][j] += sub

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        if not self.valid:
            return -1

        if row1 == 0 and col1 == 0:
            return self.dp[row2][col2]

        elif row1 == 0:
            return self.dp[row2][col2] - self.dp[row2][col1-1]

        elif col1 == 0:
            return self.dp[row2][col2] - self.dp[row1 - 1][col2]

        return self.dp[row2][col2] - self.dp[row1 - 1][col2] - self.dp[row2][col1-1] + self.dp[row1-1][col1-1]
```


方法2 方法一基础上做一些变化，dp[i][j]改为表示i, j位置的元素左边所有元素和它自己的累加和，这样update时候至多更新一行数据，求和时候求多行累加和，这样update复杂度低一些，sumRegion计算复杂度稍微高一点
快了不少

![image.png](https://pic.leetcode-cn.com/6ebaee02e804120d96f47533a584223f97912e042edef746fb283101bf788c54-image.png)
```
from typing import List
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.valid = True

        if len(matrix) == 0 or len(matrix[0]) == 0:
            self.valid = False
            return

        self.m = len(matrix)
        self.n = len(matrix[0])
        self.dp = [[0 for _ in range(self.n)] for _ in range(self.m)]
        self.data = matrix

        # dp计算累加和
        for i in range(self.m):
            self.dp[i][0] = matrix[i][0]
            for j in range(1, self.n):
                self.dp[i][j] = matrix[i][j] + self.dp[i][j-1]

    def update(self, row: int, col: int, val: int) -> None:
        self.data[row][col] = val
        for j in range(col, self.n):
            if j == 0:
                self.dp[row][j] = self.data[row][j]
            else:
                self.dp[row][j] = self.data[row][j] + self.dp[row][j-1]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        ans = 0
        for row in range(row1, row2+1):
            if col1 == 0:
                ans += self.dp[row][col2]
            else:
                ans += self.dp[row][col2] - self.dp[row][col1-1]
        return ans

```

方法三 上面两种方法乱七八糟边界判断太多了，把前缀和存储方式换一下，存储时候往右下方向偏移一个位置，这样可以把各种烦人的边界判断去掉，然后换个思路，update时候把被更新位置的最新数值存下来，还是维护二维的
累加和，这样update时候会很快速，在sumRegion计算时候，检查每一个值被更新的位置是不是落在目标矩形区域里面的，如果落在区域里面，就更正最后计算结果，增加对应的增量，缺点是在update数据比较多时候，会拖慢sumRegion计算速度， 总体下来根方法2差不多

![image.png](https://pic.leetcode-cn.com/fab2ef4050eb8b0acc8f6aae68ce2ef8d9a03e028920bd5822b275b06d219b73-image.png)


```
from typing import List

class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return

        self.m = len(matrix)
        self.n = len(matrix[0])
        self.dp = [[0]*(self.n+1) for _ in range(self.m+1)]
        self.data = matrix
        self.update_val = {}

        # dp计算累加和
        for i in range(self.m):
            for j in range(self.n):
                self.dp[i+1][j+1] = self.dp[i][j+1] + self.dp[i+1][j] - self.dp[i][j] + matrix[i][j]

    def update(self, row: int, col: int, val: int) -> None:
        self.update_val[(row, col)] = val - self.data[row][col]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        ans = self.dp[row2+1][col2+1] - self.dp[row1][col2+1] - self.dp[row2+1][col1] + self.dp[row1][col1]

        for i, j in self.update_val:
            if i >= row1 and i <= row2 and j >= col1 and j <= col2:
                ans += self.update_val[(i, j)]
        return ans
```
