### 解题思路
题目有说：如果有多个答案，则返回二维数组中最后出现的边。

所以我们设一个 answer，然后遍历每一条边，如果那条边是「不必要的边」，则把 answer 设为该边。

但是如何找到不必要的边？这时候就要用到一个数据结构 ——— 并查集：

我们可以想成有一个的图，里面有很多树（单一节点也视为树），然后提供两个操作：

（一）查询给定节点所在的树之根节点。
（二）合并颗树。

此时，我们可以用这个数据结构来解这一题。

如前面所述，我们可以遍历每一条边，而遍历到该条边时我们如果查询这条边左右两个顶点所在到树之根节点相同，即代表两个顶点在同一棵树，故该条边为当前情况「不必要的边」。

如果那一条边是必要的，那代表两个顶点代表着两颗不同的树，此时我们将他们合并为同一棵。

但是有几个重点：

（一）这段代码的正确性是基于题目要求「最后出现的边」，所以如果前面的边是可选的，我就先选不会影响答案。

（二）如果今天是返回任意的一组答案，然后那组答案包括全部「不必要的边」，那么这段程式也是可以的，这又是基于只要任意一组，我可以直接选前面出现的边。

（三）如果今天每道边有不同的权重（weight），则本解法就不能使用。本题为那种情况的一个特例（每条边权重相同）。请参考 最小生成树 问题，常见以 Prim 算法或是 Kruskal 算法解。

### 代码

```python3

# 这个并查集是比较简单的，在极端情况下 find_root() 查询要查询整棵树，但考虑到数据范围较小，并不会有太大的影响，故没针对此部分进行优化。
class disjoint:
    def __init__(self, N):
        self.array = [-1] * N
        
    def find_root(self, i):
        while self.array[i] != -1:
            i = self.array[i]
        return i
    
    def union(self, i, j):
        i = self.find_root(i)
        j = self.find_root(j)
        if (i != j) or (i == -1 and j == -1):
            self.array[i] = j
            return j
        else:
            return -1
    
        
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        a = set()
        for i in edges:
            a.add(i[0])
            a.add(i[1])
            
        tree = disjoint(len(a) + 1)
        
        answer = None
        
        for i in edges:
            x, y = tree.find_root(i[0]), tree.find_root(i[1])
            if (x != y) or (x == -1 and y == -1):
                tree.union(i[0], i[1])
            else:
                answer = i
        
        return answer
```