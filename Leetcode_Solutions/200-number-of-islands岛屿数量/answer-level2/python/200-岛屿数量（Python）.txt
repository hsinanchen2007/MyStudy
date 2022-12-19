本题是典型的深度优先遍历算法题，也是我最近钻研的一类型题目。其实这题目的思路也比较简单，就是两次循环遍历grid数组，看grid区域内是否有全1连贯的小区域，这个就对应这岛屿，然后每次找到了一个岛屿后，就要把该岛屿的所有"1"都变成'0"了，防止回溯，
具体如下图所示：
![ca7bff94bf6f6c16ff08a39758e402b.jpg](https://pic.leetcode-cn.com/04c4bcf66c375cc3f74cf16013fce47a9d7e566c23b74fd92187a8ab35bd3064-ca7bff94bf6f6c16ff08a39758e402b.jpg)

那么怎么确认岛屿的数量呢？这儿的关键就是：只要有多少个起点为"1"，岛屿就有多少个，仔细想想，确实也是这样。好了，关键点都说完了，直接上代码吧。

代码如下：
```Python
class Solution(object):
    # 本题采用深度优先遍历方法
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        # 记录岛屿的数量
        island_count = 0

        # 深度优先遍历函数
        def dfs(row, col):
            if row not in range(len(grid)) or col not in range(len(grid[0])) or grid[row][col] == "0":
                return
            # 当前位置为"1"的话，遍历完改为"0"
            grid[row][col] = "0"
            # 上下左右四个方向遍历
            dfs(row, col-1)
            dfs(row+1, col)
            dfs(row, col+1)
            dfs(row-1, col)

        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == "1":
                    # 有多少个起点为"1"，就有多少个岛屿
                    island_count += 1
                    dfs(row, col)

        return island_count


if __name__ == "__main__":
    grid = [["1","1","1","1","0"],["1","1","0","1","0"],
            ["1","1","0","0","0"],["0","0","0","0","0"]]
    print(Solution().numIslands(grid))
```
但是执行效率很低，我看了网上的帖子，方法都大同小异，不懂为什么效率这么低，是不是用的人多了啊啊哈哈哈哈哈哈哈。
如果大家有更好的方法，也希望积极留言啊！！！