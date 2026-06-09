```
'''
LeetCode 684. Redundant Connection
We are given a "tree" in the form of a 2D-array, with distinct values for each node.
In the given 2D-array, each element pair [u, v] represents that v is a child of u in the tree.
We can remove exactly one redundant pair in this "tree" to make the result a tree.
You need to find and output such a pair. If there are multiple answers for this question,
output the one appearing last in the 2D-array. There is always at least one answer.
Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: Original tree will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [1,3], [3,1]]
Output: [3,1]
Explanation: Original tree will be like this:
  1
 / \\
2   3
Note:
The size of the input 2D-array will be between 1 and 1000.
Every integer represented in the 2D-array will be between 1 and 2000.

题目大意：
684. 冗余连接
在本问题中, 树指的是一个连通且无环的无向图。
输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。
附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。
结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点u 和v的无向图的边。
返回一条可以删去的边，使得结果图是一个有着N个节点的树。
如果有多个答案，则返回二维数组中最后出现的边。答案边 [u, v] 应满足相同的格式 u < v。
示例 1：
输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的无向图为:
  1
 / \
2 - 3
示例 2：
输入: [[1,2], [2,3], [3,4], [1,4], [1,5]]
输出: [1,4]
解释: 给定的无向图为:
5 - 1 - 2
    |   |
    4 - 3
注意:
输入的二维数组大小在 3 到 1000。
二维数组中的整数在1到N之间，其中N是输入数组的大小。

回答你的问题：首先什么是没有环的树？　就是每个节点都没有闭环。　只是一个方向的走，　不能倒着再回来。　对吧？
树都没有环，你说的对，就是没有首尾链接，树一定无环。

关于拓扑排序：你看不懂，很正常。。。因为你可能搜的不对
拓扑排序其实是图算法思想那边的，分为深度优先遍历dfs，广度优先遍历bfs。
参考：https://www.cnblogs.com/qzhc/p/10291430.html

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
你给的代码我没看懂。。。p = list(range(max(reduce(operator.add, edges)) + 1))，这种高阶写法我不会。。你能给我讲讲吗
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

思考路程：
1,再给你复习一下并查集，因为我感觉你懂的不是很透彻，给你再写一遍
我们只需找到已经连接的图中出现的第一条边。下面将重点介绍实现 DSU 的细节。
一个 DSU 数据结构可以用来维护图形连接组件的数据，并快速查询它们。有两种操作：
dsu.find(node x)，找到元素 x 所在的集合的代表，该操作也可以用于判断两个元素是否位于同一个集合。
dsu.union(node x, node y)，把元素 x 和元素 y 所在的集合合并，要求 x和 y 所在的集合不相交，如果相交则不合并。
为了实现这一点，我们跟踪父结点，它会记录同一连接节点中较小结点的所在的集合。如果结点是它自己的父结点，我们将其称为连接结点的领导者。

DSU 结构的简单实现如下所示：
伪代码 ：
我们使用两种技术来提高运行时的复杂性：路径压缩和按秩合并。
路径压缩涉及将 find 函数中的 x=parent[x] 更改为parent[x]=find(parent[x])。
按秩合并涉及到将发现的工作量平均分配给领导者。
每当 dsu.union(x, y) 时，我们都有两个领导者 xr，yr，并且我们要选择是要 parent[x]=yr 还是 parent[y]=xr。
我们选择有更多子节点的领导者作为领导者。
具体地说，rank 的含义是 x 的跟随者少于 2 ^ rank[x]，这个策略可以作为 dsu.find 中的递归循环可中的界限。

2，图拓扑排序
学习：https://www.cnblogs.com/gd-luojialin/p/8509736.html
拓扑排序步骤：
1.寻找出最开始的结点（因为是有向图，可以按箭头方向。无向图可任意）。
2.记住，记录一个点后，与这个点有关的所有边全部删除。如：记录点A后，那么A->B、A->C、A->D之间的边全部删除。
3.再一次寻找新的开始结点。。。重复以上步骤。。。。。。。。。。。。

对于本题：
1，并查集思想解题
并查集的初始化就是每个点只属于自己标记的集合，即p[x]=x。
遍历边，如果两个点集合不同，那就合并进同一个集合，这里用了递归修改集合。
如果遍历边的过程中，发现两个点已经加进过之前的集合了，那就说明成环了，这时就可以输出了。
这就是传统并查集的做法。
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        p = [i for i in range(len(edges) + 1)]
        p = [*range(len(edges) + 1)]      #并查集元素初始化
        def f(x):
            if p[x] != x:       #递归修改所属集合,看上面dsu定义
                p[x] = f(p[x])  #如果结点是它自己的父结点，我们将其称为连接结点的领导者，保证p[x]=x这就是求领导节点的函数
            return p[x]
        for x, y in edges:      #遍历边
            px, py = f(x), f(y)
            if px != py:        #检查集合，领导节点是否相同，如果集合不同就合并
                p[py] = px
            else:
                return [x, y]   #集合相同就返回答案

利用py集合特性也可以做并查集，本质上没有区别，不过不用递归了，其实就是靠字典实现的并查集
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        p = {i: {i} for i in range(1, len(edges) + 1)}  #并查集初始化，{1: {1}, 2: {2}, 3: {3}, 4: {4}}
        for x, y in edges:
            if p[x] is not p[y]:    #如果两个集合地址不一样
                p[x] |= p[y]        #合并集合
                for z in p[y]:
                    p[z] = p[x]     #修改元素集合标记的指针地址
            else:
                return [x, y]

2，拓扑排序
利用数组degree记录各顶点的度。
利用数组neighbor记录各顶点的邻接顶点。
从度为1的节点出发进行拓扑排序，剩余边中在edges中排最后的那条即为答案。
拓扑排序步骤：
1.寻找出最开始的结点（因为是有向图，可以按箭头方向。无向图可任意）。
2.记住，记录一个点后，与这个点有关的所有边全部删除。如：记录点A后，那么A->B、A->C、A->D之间的边全部删除。
3.再一次寻找新的开始结点。。。重复以上步骤。。。。。。。。。。。。
直接看代码

# 并查集
class Solution1:
    def findRedundantConnection(self, edges):
        p = [i for i in range(len(edges) + 1)]
        p = [*range(len(edges) + 1)]      #并查集元素初始化
        def f(x):
            if p[x] != x:       #递归修改所属集合,看上面dsu定义
                p[x] = f(p[x])  #如果结点是它自己的父结点，我们将其称为连接结点的领导者，保证p[x]=x这就是求领导节点的函数
            return p[x]
        for x, y in edges:      #遍历边
            px, py = f(x), f(y)
            if px != py:        #检查集合，领导节点是否相同，如果集合不同就合并
                p[py] = px
            else:
                return [x, y]   #集合相同就返回答案

# 拓扑排序，速度更快
class Solution2(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        import collections
        neighbor = collections.defaultdict(set) # return defaultdict(set, {})
        degree = collections.defaultdict(int) # defaultdict(int, {})
        for s, t in edges:
            neighbor[s].add(t) # return defaultdict(set, {s: {t}, t: {s}})
            neighbor[t].add(s) # 正反两个方向构造，因为这是无向图，无向图其实就是双向图
            degree[s] += 1 # return defaultdict(int, {s: 1})
            degree[t] += 1 # 边的两个节点的度+1
        # 至此，将输入图，转成了字典，并且记录了各个节点的度
        # (degree) defaultdict(<class 'int'>, {1: 3, 2: 2, 3: 2, 4: 2, 5: 1})
        degOnes = [k for k, v in degree.items() if v == 1]  #取出度为1的点
        while degOnes:
            ndegOnes = [] # 保存经过一次拓扑排序后度为1的点
            for s in degOnes: #遍历全部度为1的节点
                deletes = set() #要删除的点的集合
                for t in neighbor[s]: # 遍历s的全部临接节点
                    degree[t] -= 1 # 因为后面将该点添加到删除集合了，所以该点度-1
                    if degree[t] == 1: ndegOnes.append(t) # 如果该点度为1了，那么保存在ndegones列表
                    deletes.add(t) # 存入要删除的点的集合
                for t in deletes: neighbor[t].remove(s) #将要删除的点从图中移除
                del degree[s]
                del neighbor[s] #清空他们便于下一次循环
            degOnes = ndegOnes # 更新degOnes为最新一轮的度为1的节点集合
        for s, t in edges[::-1]: # edges[::-1]其实是edges的反向列表,因为
            if min(degree[s], degree[t]) > 1: return [s, t] #度不为1的就是要删除的结果
        # 因为无环图经过拓扑排序，将为空
        # 遍历拓扑排序后的图，如果一对边的度有大于1的，那说明，这对边有问题，需要去掉，也就是结果

if __name__ == '__main__':
    edges =[[1,2], [2,3], [3,4], [1,4], [1,5]]
    s1 = Solution1()
    print("并查集")
    print(s1.findRedundantConnection(edges))

    s2 = Solution2()
    print("拓扑排序")
    print(s2.findRedundantConnection(edges))
'''
class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        import collections
        neighbor = collections.defaultdict(set) # return defaultdict(set, {})
        degree = collections.defaultdict(int) # defaultdict(int, {})
        for s, t in edges:
            neighbor[s].add(t) # return defaultdict(set, {s: {t}, t: {s}})
            neighbor[t].add(s) # 正反两个方向构造，因为这是无向图，无向图其实就是双向图
            degree[s] += 1 # return defaultdict(int, {s: 1})
            degree[t] += 1 # 边的两个节点的度+1
        # 至此，将输入图，转成了字典，并且记录了各个节点的度
        # (degree) defaultdict(<class 'int'>, {1: 3, 2: 2, 3: 2, 4: 2, 5: 1})
        degOnes = [k for k, v in degree.items() if v == 1]  #取出度为1的点
        while degOnes:
            ndegOnes = [] # 保存经过一次拓扑排序后度为1的点
            for s in degOnes: #遍历全部度为1的节点
                deletes = set() #要删除的点的集合
                for t in neighbor[s]: # 遍历s的全部临接节点
                    degree[t] -= 1 # 因为后面将该点添加到删除集合了，所以该点度-1
                    if degree[t] == 1: ndegOnes.append(t) # 如果该点度为1了，那么保存在ndegones列表
                    deletes.add(t) # 存入要删除的点的集合
                for t in deletes: neighbor[t].remove(s) #将要删除的点从图中移除
                del degree[s]
                del neighbor[s] #清空他们便于下一次循环
            degOnes = ndegOnes # 更新degOnes为最新一轮的度为1的节点集合
        for s, t in edges[::-1]: # edges[::-1]其实是edges的反向列表,因为
            if min(degree[s], degree[t]) > 1: return [s, t] #度不为1的就是要删除的结果
        # 因为无环图经过拓扑排序，将为空
        # 遍历拓扑排序后的图，如果一对边的度有大于1的，那说明，这对边有问题，需要去掉，也就是结果
```
