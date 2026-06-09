```
'''
LeetCode 803 打砖块
We have a grid of 1s and 0s; the 1s in a cell represent bricks.
A brick will not drop if and only if it is directly connected to the top of the grid,
or at least one of its (4-way) adjacent bricks will not drop.
We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j),
the brick (if it exists) on that location will disappear, and then some other bricks may drop because of that erasure.
Return an array representing the number of bricks that will drop after each erasure in sequence.
Example 1:
Input:
grid = [[1,0,0,0],[1,1,1,0]]
hits = [[1,0]]
Output: [2]
Explanation:
If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.
Example 2:
Input:
grid = [[1,0,0,0],[1,1,0,0]]
hits = [[1,1],[1,0]]
Output: [0,0]
Explanation:
When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move.
So each erasure will cause no bricks dropping.  Note that the erased brick (1, 0) will not be counted as a dropped brick.
Note:
The number of rows and columns in the grid will be in the range [1, 200].
The number of erasures will not exceed the area of the grid.
It is guaranteed that each erasure will be different from any other erasure, and located inside the grid.
An erasure may refer to a location with no brick - if it does, no bricks drop.

题目大意：
我们有一组包含1和0的网格；其中1表示砖块。当且仅当一块砖直接连接到网格的顶部，或者它至少有一块相邻（4 个方向之一）砖块不会掉落时，它才不会落下。
我们会依次消除一些砖块。每当我们消除 (i, j) 位置时， 对应位置的砖块（若存在）会消失，然后其他的砖块可能因为这个消除而落下。
返回一个数组表示每次消除操作对应落下的砖块数目。
示例 1：
输入：
grid = [[1,0,0,0],[1,1,1,0]]
hits = [[1,0]]
输出: [2]
解释:
如果我们消除(1, 0)位置的砖块, 在(1, 1) 和(1, 2) 的砖块会落下。所以我们应该返回2。
示例 2：
输入：
grid = [[1,0,0,0],[1,1,0,0]]
hits = [[1,1],[1,0]]
输出：[0,0]
解释：
当我们消除(1, 0)的砖块时，(1, 1)的砖块已经由于上一步消除而消失了。所以每次消除操作不会造成砖块落下。注意(1, 0)砖块不会记作落下的砖块。
注意:
网格的行数和列数的范围是[1, 200]。
消除的数字不会超过网格的区域。
可以保证每次的消除都不相同，并且位于网格的内部。
一个消除的位置可能没有砖块，如果这样的话，就不会有砖块落下。

PS：
并查集数据结构和行为总结：
1，并查集的数据结构就是使用数组存放一颗树，每一个下标i的pre[i]的值为父亲的下标。
find过程就是重复一直到祖先为止，终止条件是i=pre[i],也就是父亲是自己
2，数组初始化为每个元素的父亲为自己(带权并查集的权值数组初始化需要根据题意)，union操作合并两个祖先，如果一个连通块有公共的属性，
或者权值的计算，一般也在union函数内，权值数组i的值就是i到pre[i]的权值
并查集的特点：
合并的是通过祖先相连实现，丢失了具体的连接信息（比如告诉你a和b相连，实现的数据结构是father(a)和father（b）相连），
因此当删除某个节点或者单个连通关系时更新并查集，因为原来具体的连通状态信息已经丢失了
每个点都是对等的，如果有个别点存在特殊情况比如a点必须做祖先啥的，不适用
由于1和2，并查集只能计算连通性，对应图的dfs、bfs等连通算法，图额外的最短路径等，并查集无法做到（每一步都是只计算连通性，仅此）

解题思路：逆序思考 + 并查集
与其考虑在每次操作后，有多少砖块落下，我们不如倒过来考虑这个过程：
每次我们加上一个砖块，并计算有多少额外的砖块因为这个砖块的增加而和网格的顶部直接或间接相连。这样我们就可以用并查集来解决这个问题了。
首先我们添加一个虚拟的节点，它的编号为 R * C（网格中的节点编号为 [0, R * C - 1]），代表网格的顶部，任何第一行的砖块都会与它相连。
对于网格中的每一个位置，如果它在所有操作结束后仍然有砖块，那么就将它和四连通（上下左右）的四个位置（如果对应位置也有砖块）进行合并。
这样，我们就得到了在所有操作结束后，网格对应的并查集状态。
随后我们逆序地处理这些操作。对于每一次操作的位置 (r, c)，如果这个位置原本就没有砖块，那么不会有任何变化；
如果这个位置原本有砖块，那么砖块从无到有的过程就会使得 (r, c) 四连通的四个位置相连，如果这四个位置中的某些位置有砖块，那么就将这些位置合并，
如果 r == 0，砖块的位置在第一行，那么还需要和网格的顶部合并。我们在并查集中额外加入数组 sz[] 表示集合中节点的数目，
这样在每次操作后，sz[findset(R * C)] 的变化量就是和顶部相连的砖块数的变化量，也就是顺序考虑时落下来的砖块数量。
具体看代码：
简单说下整体思想，先深度拷贝gird，将grid中hits部位的砖头全部归0，构造并查集，作为最初并查集，此时拿砖转化为忘hits的位置放砖。
然后反转hits，拿和放是反着的。不断放砖，保存每次放砖并查集R*C集合的数量变化，但别忘了减去多放上去的这个砖自身并不计算。
返回再次反转的结果，就是答案。

个人觉得，放砖更好统计并查集状态，减少遍历次数，如果是拿砖，还需要往上遍历，增加算法时间耗时。
'''
class DSU:
    def __init__(self, R, C):
        #R * C is the source, and isn't a grid square
        self.par = list(range(R*C + 1)) # [0, 1, 2, 3, 4, 5, 6, 7, 8],并查集初始化各自为各自的集合
        self.rnk = [0] * (R*C + 1) # 相当于合并次数
        self.sz = [1] * (R*C + 1) # 表示集合中节点的数目，由于初始化每个节点都在自己的集合，所以都是1

    def find(self, x):
        if self.par[x] != x: # find终止条件就是一直向上find，直到parent[x]=x，自己就是代表节点
            self.par[x] = self.find(self.par[x]) # 递归查找
        return self.par[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr: return
        if self.rnk[xr] < self.rnk[yr]:
            xr, yr = yr, xr
        if self.rnk[xr] == self.rnk[yr]:
            self.rnk[xr] += 1

        self.par[yr] = xr
        self.sz[xr] += self.sz[yr] # 集合节点数量合并

    def size(self, x):
        return self.sz[self.find(x)] # 表示集合中节点的数目

    def top(self): # 求顶部那个集合的大小
        # Size of component at ephemeral "source" node at index R*C,
        # minus 1 to not count the source itself in the size
        return self.size(len(self.sz) - 1) - 1 # len(self.sz) - 1其实就是R*C

class Solution(object):
    def hitBricks(self, grid, hits):
        R, C = len(grid), len(grid[0])

        def index(r, c): # 将坐标(x,y)转化为index
            return r * C + c

        def neighbors(r, c): # 迭代生成符合题意的邻居节点
            for nr, nc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                if 0 <= nr < R and 0 <= nc < C:
                    yield nr, nc

        A = [row[:] for row in grid] # [[1, 0, 0, 0], [1, 1, 1, 0]]，其实就是grid，相当于深拷贝了
        for i, j in hits: # 先去掉hits里面所有位置的砖头
            A[i][j] = 0

        dsu = DSU(R, C) # 下面开始构造不考虑hits情况下的并查集
        for r, row in enumerate(A):
            for c, val in enumerate(row): # (r,c)相当于位置，val为当前位置的值
                if val: # 该位置有砖头
                    i = index(r, c) # 坐标转换为index，因为使用list实现的并查集
                    if r == 0: # 是第一行顶部
                        dsu.union(i, R*C) # 合并到R*C一派，R*C是标记的顶部集合,我们定义的，因为最大index是R*C-1，设成别的也ok
                    if r and A[r-1][c]: # 不是第一行并且上一行有砖头
                        dsu.union(i, index(r-1, c)) # 合并到上一行那一派
                    if c and A[r][c-1]: # 不是最左边并且左边有砖头
                        dsu.union(i, index(r, c-1)) # 合并到最左边
        # print(dsu.par) # [0, 1, 2, 3, 4, 6, 6, 7, 0] # 这样看并查集内容，你可以放在上面循环里面打印

        ans = []
        for r, c in reversed(hits): # 反向思考，如果我们是往上放砖,
            # 为什么要反向？因为如果是拿砖，后一次会影响前一次，放砖就是前一次被后一次影响
            pre_roof = dsu.top() # 保存并查集现在的状态
            if grid[r][c] == 0: # 此处无砖，结果不变
                ans.append(0)
            else:
                i = index(r, c) # 若此处有砖，求坐标
                for nr, nc in neighbors(r, c): # 遍历四周连接砖头
                    if A[nr][nc]: # 如果有砖
                        dsu.union(i, index(nr, nc)) #归到一类
                if r == 0:
                    dsu.union(i, R*C) # 如果是顶部，归到顶部自定义的R*C类
                A[r][c] = 1 # 还原A中此处的砖头，A之前是不考虑hits处有砖的grid,必须要还原，我们是在A上计算的，也就是说hits中后面的会影响前面的
                ans.append(max(0, dsu.top() - pre_roof - 1)) # 变化后状态-变化前的状态-当前砖块的1,因为这个砖是hits加上去的
        return ans[::-1] # 结果反转，因为前面hit是反转的

if __name__ == "__main__":
    grid = [[1, 0, 0, 0], [1, 1, 1, 0]]
    hits = [[1, 0]]
    s = Solution()
    print(s.hitBricks(grid, hits))
```
