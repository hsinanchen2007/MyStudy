#### 解题思路：
题目已经提示灯是类似皇后问题的横竖对角线，完全可以按照同样的方式来考虑。

一个点被照明，可以是来自横向，竖向，和对角线四个方向的灯。
区别是可以灯光是可以叠加的，因此我们需要记录一个正方形被几个灯照亮，也就是横竖对角线上的灯的个数。
当值为 $0$ 时候就代表这个正方形是暗的，输出 $0$，当有大于 $0$ 的灯照亮时候输出 $1$。


```Python [python]
        cols = [0]*n
        rows = [0]*n
        hill_diagonals = [0]*(2*n-1)
        dale_diagonals = [0]*(2*n-1)
```
这里有个坑，数据规模到十亿时候就内存溢出了。其实我们不需要考虑这么多方格，我们只要考虑初始化时被灯照亮的区域就行了。

使用 $defaultdict$ 进行初始化即可。

```Python []
        cols = defaultdict(int)
        rows = defaultdict(int)
        hill_diagonals = defaultdict(int)
        dale_diagonals = defaultdict(int)
```



还有一个需要注意的，在我们在进行一次 query 时候，需要关掉以该点位中心的 3*3 方格的灯。此时我们要判断这几个正方形里面是不是有灯(灯是暗的等同于移除灯)。
没有灯就不需要处理，有的话则移除灯，并修改，横竖对角线上灯的个数。这里如果我们直接用 `[row，col] in lamps` 进行判断，在数据量小的时候是可以的，但是当 lamps 数据量很大，每次都进行遍历，花费的时间是很多的，因此需要在初始化时候，需要将 lamps 转化成一个字典，这样每次进行判断时候只需要 $O(1)$ 时间了。

#### 代码：

```Python [python]
from collections import defaultdict
class Solution:
    def gridIllumination(self, N: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        cols = defaultdict(int)
        rows = defaultdict(int)
        hill_diagonals = defaultdict(int)
        dale_diagonals = defaultdict(int)

        lamp_set = set()
        for row, col in lamps:                 # 初始化，统计横竖对角线上灯的个数。
            cols[col] += 1
            rows[row] += 1
            hill_diagonals[row - col] += 1
            dale_diagonals[row + col] += 1
            lamp_set.add((row, col))            # 将灯的数组转化为字典

        def state(row, col):
            return bool(cols[col] + rows[row] + hill_diagonals[row - col] + dale_diagonals[row + col])

        def turn_off(row, col):
            for i in [-1, 0, 1]:
                if 0 <= i + row < N:
                    for j in [-1, 0, 1]:
                        if 0 <= col + j < N:
                            if (i + row, j + col) in lamp_set:
                                lamp_set.remove((i + row, j + col))
                                cols[j + col] -= 1
                                rows[i + row] -= 1
                                hill_diagonals[row + i - j - col] -= 1
                                dale_diagonals[row + i + j + col] -= 1

        res = []
        for row, col in queries:
            res.append(int(state(row, col)))
            turn_off(row, col)
        return res
```