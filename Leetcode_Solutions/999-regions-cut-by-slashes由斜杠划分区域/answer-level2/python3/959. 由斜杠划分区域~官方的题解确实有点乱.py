### 解题思路
这道题完全是考察`并查集`，如果按照[每个小格分解为 3 * 3 方格。求连通分量](https://leetcode-cn.com/problems/regions-cut-by-slashes/solution/mei-ge-xiao-ge-fen-jie-wei-3-3-fang-ge-qiu-lian-to/)，那么这道题直接用BFS和DFS来求解也是可以的，但是这种方法是将每个小格子分解成`（3+）*（3+）`的方格，你有可能分解成2*2, 那么对于测试用例5将无法通过,不行你可以试试。

但是这道题，我们还是采用并查集来做做，首先在我之前的[题解-朋友圈](https://leetcode-cn.com/problems/friend-circles/solution/547-peng-you-quan-chu-bfsdfswai-huan-you-bing-cha-/)中有对并查集有介绍,

这道题的难点并不是并查集，而是如何将问题转化成并查集，问题中问的是返回区域的数量，这不出意外肯定是使用并查集：
那么如何转化呢？依照题意，1x1的方格由/, \\, 空格， 那么1x1的方格会被划分成4个部分，
1、如果是/,那么其中两两合并；
2、如果是\,那么也是两两合并；
3、如果是空，四个一起合并。
如下图，一看就能明白！！我对其中一个1x1的格子（绿色）进行分析
![image.png](https://pic.leetcode-cn.com/c8cb24b20122246c2a526e08258c9ca12a37c67115189a7874fd642deb62963d-image.png)

##### 明白的话记得点个赞呢！！

### 代码

```python3
class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        N = len(grid)
        parent = [i for i in range(4 * N * N)] # 开始的时候每个节点的帮主都是自己
        def find(parent, x): # 寻找每个节点的帮主
            if parent[x] == x:
                return parent[x]
            return find(parent, parent[x])
        
        def union(parent, x, y): # 两个人相遇， 那么各自去找教主，教主对决
            x_root = find(parent, x)
            y_root = find(parent, y)
            if x_root != y_root: # 教主不同
                parent[x_root] = y_root # 对决赢的成为新教主
        
        def union_find(grid):
            for r, row in enumerate(grid):
                for c, val in enumerate(row):
                    top = 4 * (r * N + c) 
                    if val in ['/', ' ']:
                        union(parent, top + 0, top + 1)
                        union(parent, top + 2, top + 3)
                    if val in ['\\', ' ']:
                        union(parent, top + 0, top + 2)
                        union(parent, top + 1, top + 3)

                    if r + 1 < N: 
                        union(parent, top + 3, top + (4 * N) + 0)
                    if r - 1 >= 0:# 这部分其实是多于的
                        union(parent, top + 0, top - (4 * N) + 3) 
                    if c + 1 < N:
                        union(parent, top + 2, top + 4 + 1)
                    if c - 1 >= 0: # 这部分其实也是多于的
                        union(parent, top + 1, top - 4 + 2)

            return sum(parent[x] == x for x in range(4 * N * N ))
        return union_find(grid)
```