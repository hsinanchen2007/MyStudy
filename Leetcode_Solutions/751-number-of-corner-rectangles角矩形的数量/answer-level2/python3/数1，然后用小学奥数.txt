提到数1，就不得不想到位运算。
思路是这样的：
随便揪两行出来，位运算与一下，剩几个1，得到的矩形就有几条宽n
这样的矩形中矩形总数=(n - 1) * n / 2
那么就有代码：
```python
class Solution:
    def countCornerRectangles(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0] or len(grid) == 1 or len(grid[0]) == 1:
            return 0
        row = len(grid)
        res = 0
        for i in range(row):
            for j in range(i+1, row):
                bin_i, bin_j = "".join(map(str, grid[i])), "".join(map(str, grid[j]))
                int_i, int_j = int(bin_i, 2), int(bin_j, 2)
                and_res = bin(int_i & int_j)[2:]
                cnt = and_res.count("1")
                if cnt == 0:
                    continue
                else:
                    res += cnt * (cnt-1) // 2
        return res
```
很可惜，超时了。。。。
翻了翻评论 @powcai 大佬思路是一样的，都是数1然后用公式算：
```python
class Solution:
    def countCornerRectangles(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        res = 0
        for i in range(row - 1):
            one = []
            for k in range(col):
                if grid[i][k] == 1:
                    one.append(k)
            for j in range(i+1, row):
                tmp = 0
                for t in one:
                    if grid[j][t] == 1:
                        tmp += 1
                res += tmp * (tmp - 1) // 2
        return res
```

那么问题来了。。第一种方法为啥会超时_(:з」∠)_。。有大佬指点下吗。。。
或者给个C++版本也是极好的