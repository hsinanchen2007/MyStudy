### 解题思路
总要有我这种傻瓜解法来垫底 = =
写着玩的…也不是专业的…希望能给和我一样业余的提供一点思路

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # 某个烂橘子一次的传染方式，无非是上下左右，同时在tmp数组标记这一轮被感染的位置（防止一轮连续感染多个）
        def infect(i, j, grid, tmp):
            for a, b in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                try:
                    if i + a >= 0 and j + b >= 0 and grid[i + a][
                            j + b] == 1 and tmp[i + a][j + b] != 1:
                        grid[i + a][j + b] = 2
                        tmp[i + a][j + b] = 1
                except:
                    pass
            return grid, tmp

        round = 0
        while True:
            count_before = 0
            #记录被感染位置，若该位置这一轮被感染，标记为1
            tmp = []
            #数有多少个1（好橘子），同时清空tmp
            for i in range(len(grid)):
                tmp.append([])
                for j in range(len(grid[0])):
                    tmp[i].append(0)
                    if grid[i][j] == 1:
                        count_before += 1

            #如果有好橘子，则进行‘感染’
            if count_before != 0:
                for i in range(len(grid)):
                    for j in range(len(grid[0])):
                        if grid[i][j] == 2 and tmp[i][j] != 1:
                            (grid, tmp) = infect(i, j, grid, tmp)
                round = round + 1

            count = 0
            #数是否还存在好橘子，如果数量和感染之前的好橘子数量一致，说明感染停止了，退出循环
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    if grid[i][j] == 1:
                        count += 1

            if count_before == count:
                break

        if count != 0:
            return -1
        else:
            return round