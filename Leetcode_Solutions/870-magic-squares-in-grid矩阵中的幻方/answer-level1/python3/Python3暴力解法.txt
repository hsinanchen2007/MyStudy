暂时没想到什么好的方法，坐等大神，这题出的也莫名其妙吧，只想到了遍历，一般暴力的遍历我都用Python做，因为... ...写着简单：
全靠抖机灵减少判断条件，所以会快一点... ...
![image.png](https://pic.leetcode-cn.com/acb42d2811b3516e46594de68ecb3df40aaef7ec3304f69ecd7d0ed9e1837255-image.png)
```
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        l = len(grid)
        h = len(grid[0])
        sum = 0
        # 外圈不用遍历
        for i in range(1, l - 1):
            for j in range(1, h - 1):
                # 只有中心为5才在讨论范围
                if grid[i][j] == 5:
                    temp = [0, 0, 0, 0, 0, 0, 0, 0, 0]
                    for m in range(-1, 2):
                        for n in range(-1, 2):
                            if 0 < grid[i + m][j + n] < 10:
                                temp[grid[i + m][j + n] - 1] = 1
                    print(temp)
                    flag = 1
                    # 用这个哈希表判断是否是1-9的数字都用到了，所以下面值判断三行外加一个对角线为15就是可以的
                    for num in temp:
                        flag = flag * num           
                    a = grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1]
                    if a == 15:
                        b = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1]
                        if b == 15:
                            c = grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1]
                            if c == 15:
                                d = grid[i - 1][j - 1] + grid[i + 1][j + 1]
                                if d == 10:
                                    sum = sum + 1 * flag
        return sum
```
