![image.png](https://pic.leetcode-cn.com/1f67ea06175724c93d829d33d9a0f53930d250f5068dc5fa141d9974f65bce11-image.png)



**本题的核心思路是**
1、找出所有可能的起点
2、用回溯算法穷尽所有的走法，算出最大值

**之所以说是优化版，体现在：**
1、仅仅把左下直角“∟”的点和触角的点（有一个或零个相邻的有黄金的点）作为起点，大幅度减少了工作量。
2、避免使用visited辅助变量储存回溯过程，原地纪录回溯过程，以节省开销

下面将说明：**为什么仅仅把直角左下“∟”的点和触角的点作为起点，是可行的**。
*    如果最佳挖金路线可以形成回路，那么每一点都可以作为起点。既然是回路，那么肯定有直角，不妨把左下直角“∟”设为起点（当然也可以选择左上、右上、右下直角）
*    如果最佳挖金路线不能形成回路，类似于一笔画，那么起点就是触角

另外关于回溯问题，一般都需要辅助变量来记录已经走过的路线，例如：
```
visited = set()
def traceback(i, j, accumulated_gold, visited):
    for p, q in ...
        traceback(i, j, accumulated_gold + grid[p][q], visited | {(p, q)})
```
但是这样把辅助变量传参的方式开销很大，必然影响效率。有一种原地记录的方法，将在代码中介绍，这种方法直接利用了递归的特性。

**附上整体代码如下：**
```python []
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        def could_be_the_start_point(i, j):  # 这个函数用来判断一个点是否作为起点
            if grid[i][j]:
                num = 0
                for p, q in zip((i-1, i+1, i, i), (j, j, j-1, j+1)):  # p, q是上下左右四个点
                    if 0 <= p < m and 0 <= q < n and grid[p][q]:
                        num += 1
                if num <= 1:
                    return True  # 如果是触角，那么作为起点解决最佳路线是一笔画的情形
                if num == 2 and 0 <= i-1 < m and 0 <= j < n and grid[i-1][j] and 0 <= i < m and 0 <= j+1 < n and grid[i][j+1]:
                    return True  # 如果是左下直角“∟”，那么作为起点解决最佳路线是回路的情形
            return False

        def mine(i, j, accumulated_gold):  # 这个函数用来回溯
            continue_to_mine = False  # 设置一个变量来记录是不是挖到底了
            for p, q in zip((i-1, i+1, i, i), (j, j, j-1, j+1)):  # p, q是上下左右四个点
                if 0 <= p < m and 0 <= q < n and grid[p][q]:  # 只要某个方向有黄金，就往那个方向挖
                    gold_in_place = grid[p][q]  # gold_in_place 记录黄金的量
                    grid[p][q] -= gold_in_place  # 把这个地方的黄金置0，这样以后就不会重复挖了（原地记录）
                    mine(p, q, accumulated_gold + gold_in_place)  # 继续挖，记得把刚才挖到的黄金加到总量里
                    grid[p][q] += gold_in_place  # 挖好以后把黄金放回去，才不影响其他的回溯路径，当做什么都没发生过
                    continue_to_mine = True  # 任何一个方向还有黄金，就表示还没挖到底
            if not continue_to_mine:  # 如果挖到底了，回溯结束，记录黄金总数
                self.max_accumulated_gold = max(self.max_accumulated_gold, accumulated_gold)

        m, n = len(grid), len(grid[0])  # m, n分别表示矿区的深度和宽度
        self.max_accumulated_gold = 0  # self.max_accumulated_gold 记录各条挖宝路线的最大黄金总数。当然也可以直接用 max_accumulated_gold 变量，然后 global max_accumulated_gold
        for i in range(m):
            for j in range(n):  # 遍历矿区
                if could_be_the_start_point(i, j):  # 考虑每个点是否作为起点
                    gold_in_place = grid[i][j]  # gold_in_place 记录起点的黄金量
                    grid[i][j] -= gold_in_place  # 把起点的黄金置0，这样以后就不会重复挖了
                    mine(i, j, gold_in_place)  # 进入回溯
                    grid[i][j] += gold_in_place  # 挖好以后把黄金放回去，才不影响其他的回溯路径，当做什么都没发生过
        return self.max_accumulated_gold  # 返回最佳路线的最大黄金总数。
```

2020/03/02更新：
感谢 [@luuuuuuu](/u/luuuuuuu/)大佬的指正，这个例子通过不了：
[[6,6,9],
 [5,0,7],
 [6,9,8],
 [5,0,9],
 [5,5,9],
 [0,0,0]]
两个环的情形，触角和直角都不能作为最优路线的起点。
那看来还是以所有点为起点遍历吧哈哈