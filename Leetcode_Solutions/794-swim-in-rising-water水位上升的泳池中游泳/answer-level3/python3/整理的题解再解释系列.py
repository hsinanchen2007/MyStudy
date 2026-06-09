```
'''
LeetCode 778 水位上升的泳池中游泳
On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).
Now rain starts to fall. At time t, the depth of the water everywhere is t.
You can swim from a square to another 4-directionally adjacent square
if and only if the elevation of both squares individually are at most t.
You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.
You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?
Example 1:
Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:
Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6
The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
Note:
2 <= N <= 50.
grid[i][j] is a permutation of [0, ..., N*N - 1].

题目大意：
在一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置 (i,j) 的平台高度。
现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，
但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。
当然，在你游泳的时候你必须待在坐标方格里面。
你从坐标方格的左上平台 (0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台 (N-1, N-1)？
示例 1:
输入: [[0,2],[1,3]]
输出: 3
解释:
时间为0时，你位于坐标方格的位置为 (0, 0)。
此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。
等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置
示例2:
输入: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
输入: 16
解释:
 a0  a1  a2  a3  a4
24 23 22 21  a5
a12 a13 a14 a15 a16
a11 17 18 19 20
a10  a9  a8  a7  a6
最终的路线用加粗进行了标记，我加了a
我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的
提示:
2 <= N <= 50.
grid[i][j] 位于区间 [0, ..., N*N - 1] 内。

解题思路：
方法一： 堆【通过】
简单说下怎么可以想到使用堆，也就是优先级队列，默认最小堆。
对于这道题，我们想走到最后且耗时最少？
简单想，由起始点开始，每次都走当前所在的点周围水位最低的点，但是这会有一个问题，当某个点的周围最小的点对应的路径可能反而是比较大的，
那么我们优化，即所有的能走的点中我们永远只走水位最低的点，每到一个点，我们再记录所有的能走的点，并再次选择所有能走的点中水位最低的点，
这种方法不仅仅考虑了周围，而是考虑了全部。
什么数据结构可以支持这种全部数据的分布调节来返回最小值，那当然就是最小堆，始终调节保证堆顶为堆中最小。
对于本题：
用优先队列保存下一步可以游向的平台，每次都选择高度最小的平台。以这种方式到达终点时，路径中遇到的最高平台就是答案。
import heapq
class Solution(object):
    def swimInWater(self, grid):
        N = len(grid)

        seen = {(0, 0)}
        pq = [(grid[0][0], 0, 0)] # 初始化堆 -----（值，x，y）
        ans = 0
        while pq:
            d, r, c = heapq.heappop(pq)
            ans = max(ans, d) # 走到最后的路径中的最大值
            if r == c == N-1: return ans # 走到终点（N-1，N-1）
            for cr, cc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)): # 遍历上下左右
                if 0 <= cr < N and 0 <= cc < N and (cr, cc) not in seen: # 在范围内+没走过
                    heapq.heappush(pq, (grid[cr][cc], cr, cc)) # 能走到的位置入堆
                    seen.add((cr, cc)) # 记录走过的位置
方法2：二分+DFS
可以发现是否能完成是根据时间的单调函数，因此可以用二分搜索来找到最少耗时。
即找到最小 T 使得从起点游到终点成为可能。设最少耗时为 T，用深度优先搜索来检查是否有可能从起点游到终点。
直接看代码把
'''
class Solution(object):
    def swimInWater(self, grid):
        N = len(grid)

        def possible(T): # 是否可以通过dfs的函数
            stack = [(0, 0)] # 栈实现DFS
            seen = {(0, 0)}
            while stack:
                r, c = stack.pop()
                if r == c == N-1: return True # 到达终点
                for cr, cc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                    if (0 <= cr < N and 0 <= cc < N
                            and (cr, cc) not in seen and grid[cr][cc] <= T):
                        stack.append((cr, cc))
                        seen.add((cr, cc))
            return False

        lo, hi = grid[0][0], N * N
        while lo < hi: # 关于你说的二分法，上次你问不是分大于小于等于嚒，这道题就不可以这么写，因为要求最小值
            mi = (lo + hi) // 2
            # print(lo,mi,hi,possible(mi))
            if not possible(mi):
                lo = mi + 1
            else: # 因为要求最小，即使返回true，我们也要压缩上限，因为有好多解，mid可能会跳跃最优解，因此需要压缩上下限
                hi = mi
        return lo


if __name__ == "__main__":
    grid  = [[0, 1, 2, 3, 4], [24, 23, 22, 21, 5], [12, 13, 14, 15, 16], [11, 17, 18, 19, 20], [10, 9, 8, 7, 6]]
    s =Solution()
    print(s.swimInWater(grid))
```
