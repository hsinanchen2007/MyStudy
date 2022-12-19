### 解题思路
和12题思路基本一致，只是增加了一个discoveryed_plots存储走过的点，此外加入了canBeIn方法来判断是否可以走到某个点

建议亲自写一遍本题或12题体会思路

### 代码

```python3
class Solution:
    discoveryed_plots = []

    # 是否可以走到某个点
    # 如果这个点已经被探索过/无法进入，返回False，否则返回True
    def canBeIn(self, i, j, k):
        if ([i, j] in self.discoveryed_plots):
            return False
        else:
            num = 0
            for each in (str(i) + str(j)):
                num += int(each)

            if num > k: return False
            else      : return True

    # row对应横列
    # col对应纵列
    def discovery(self, matrix, row, col, k):
        if (row < 0 or row >= len(matrix) or col < 0 or col >= len(matrix[0])):
            return False

        canBeIn = self.canBeIn(row, col, k)
        print(row, col, canBeIn)
        if (canBeIn is False): 
            return False
        else:
            self.discoveryed_plots.append([row, col])

        return  self.discovery(matrix, row + 1, col, k) or \
                self.discovery(matrix, row - 1, col, k) or \
                self.discovery(matrix, row, col + 1, k) or \
                self.discovery(matrix, row, col - 1, k)

    def movingCount(self, m: int, n: int, k: int) -> int:
        self.discoveryed_plots = []
        matrix = [["*"] * n] * m
        self.discovery(matrix, 0, 0, k)

        return len(self.discoveryed_plots)
```