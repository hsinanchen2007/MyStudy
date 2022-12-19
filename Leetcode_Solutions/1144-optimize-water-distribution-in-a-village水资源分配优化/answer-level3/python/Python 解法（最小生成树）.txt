## 思路

如果供水只能通过铺管道的方法，不能在屋子里建水井，

然后问所有房子都供上水的最低成本，那么这道题就是[1135. 最低成本联通所有城市](https://leetcode-cn.com/classic/problems/connecting-cities-with-minimum-cost/description/)，

现在多了一个建造水井的选项，就有了一点变化。

那么能不能把建造水井也看成是铺设管道呢？

题目给的房子编号是从1 ~ n，那么不妨人为地给地下水标个编号0，这样就可以把水井转化成铺管道：

举例：对于wells = [1, 2, 2]， 就可以看作为pipes = [[1, 0, 1], [2, 0, 2], [3, 0, 2]]，

分别代表，从1号房跟地下水连接的开销为1，从2号房跟地下水的连接开销为2，从3号房跟地下水的连接开销为2

这样再用[1135. 最低成本联通所有城市](https://leetcode-cn.com/classic/problems/connecting-cities-with-minimum-cost/description/)的解法，即最小生成树的Kruskal算法解题即可。

流程如下：

1. 把所有的边按权重（成本）从小排到大 （这一步用优先级队列实现）
2. 从权重最小的边开始处理，如果当前最小边的两端没有连接在一起（这一步用并查集检验），那么就需要这条边，在并查集里把两个端点 union 在一起，并累加这条边的权重。如果当前最小边的两端已经连接在一起，则说明这条边是多余的，无需处理。
3. 重复步骤2， 直到所有房屋都已经连接在一起为止

## 代码实现
```Python
class UnionFindSet(object):
    def __init__(self, n):
 
        self.roots = [i for i in range(n + 1)]
        self.rank = [0 for i in range(n + 1)]
        self.count = n
 
    def find(self, member):
        tmp = []
        while member != self.roots[member]:
            tmp.append(member)
            member = self.roots[member]
        for root in tmp:
            self.roots[root] = member
        return member
 
    def union(self, p, q):
        parentP = self.find(p)
        parentQ = self.find(q)
        if parentP != parentQ:
            if self.rank[parentP] > self.rank[parentQ]:
                self.roots[parentQ] = parentP
            elif self.rank[parentP] < self.rank[parentQ]:
                self.roots[parentP] = parentQ
            else:
                self.roots[parentQ] = parentP
                self.rank[parentP] -= 1
            self.count -= 1
            
class Solution(object):
    def minCostToSupplyWater(self, n, wells, pipes):
        """
        :type n: int
        :type wells: List[int]
        :type pipes: List[List[int]]
        :rtype: int
        """
        from heapq import *
        for i, well in enumerate(wells):
            pipes.append([0, i + 1, well])#转井为管
        
        queue = []
        ufs = UnionFindSet(n)
        for start, end, cost in pipes:
            queue.append([cost, start, end]) 
            
        heapify(queue)
        res = 0
        while ufs.count > 0:           
            cost, start, end = heappop(queue)
            if ufs.find(start) == ufs.find(end):
                continue
            res += cost
            ufs.union(end, start)
        return res
```

## 复杂度分析

时间复杂度：$O(nlogn)$

空间复杂度：$O(n)$
