# 本题只要想清楚该使用广度优先搜索就解决一大半了。
# 广度优先搜索即搜索一个节点的所有关联节点之后，再进行下一个节点的搜索。

# 在本题中，我们首先把初始时的所有的坏橘子拎出来当作第一群节点，然后依此访问这几个橘子周围的空间，这就是广度优先搜索了。然后把这几个橘子周围受到感染的橘子作为第二群节点，重复这样的操作，直到没有可以感染的橘子为止。

# 最终，我们可以得到我们上一步操作的重复次数，也就是感染全部橘子所需的分钟数。但是如果最后还有新鲜的橘子存在，那么就表示无法感染所有的橘子。

# ```py
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        #获得整个空间的大小
        R, C = len(grid), len(grid[0])
        #用于获取相邻橘子的坐标
        def neighbors(r, c):
            for nr, nc in [[r - 1, c], [r, c - 1], [r, c + 1], [r + 1, c]]:
                # 确认坐标没有超出给定的空间
                if 0 <= nr < R and 0 <= nc < C:
                    # 返回合法的坐标，通过 yield 将函数转变为 generator，也就是可以通过 for 或者 next 获取元素
                    yield nr, nc

        #使用List 模拟队列，记录广度搜索的元素
        rot_queue = []
        #获得初始的坏橘子
        for r, row in enumerate(grid):
            for c, orange in enumerate(row):
                if orange == 2:
                    rot_queue.append([r, c, 0])
        
        ##将总时间设为函数内的全局变量
        minute = 0
        ##进行广度搜索，只要队列中还有元素就表示便利没有结束
        while rot_queue != []:
            #将即将访问的橘子踢出队列
            rot_orange = rot_queue.pop(0)
            #访问这个橘子周围的橘子
            for nr, nc in neighbors(rot_orange[0], rot_orange[1]):
                #如果周围有未感染的橘子
                if grid[nr][nc] == 1:
                    #感染他们
                    grid[nr][nc] = 2
                    #记录当前分钟数，并将感染后的橘子加入待广度搜索的队列
                    minute = rot_orange[2]+1
                    rot_queue.append([nr, nc, minute])

        #搜查幸存橘🍊
        for row in grid:
            for orange in row:
            #一旦发现幸存橘，就可以证明无法感染完所有橘子，则返回-1
                if orange == 1:
                    return -1
        #如果没有幸存橘，则返回相应的分钟数
        return minute
# ``` 

