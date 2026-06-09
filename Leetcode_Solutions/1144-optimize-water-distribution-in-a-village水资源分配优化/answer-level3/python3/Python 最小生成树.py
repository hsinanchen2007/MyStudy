
```
'''
把水井当成一个虚拟节点，虚拟节点到每一个其他节点的距离就是这个节点造水井的开销，
求整个图的最小生成树
'''

from typing import List
from queue import PriorityQueue

class MergeSet:
    def __init__(self):
        self.m = {}
        self.__root_cnt = 0

    def getRoot(self, node):
        root = node
        buf = []
        while self.m[root] != root:
            buf.append(root)
            root = self.m[root]
        for node in buf:
            self.m[node] = root

        return root


    def merge(self, a, b):
        for node in [a, b]:
            if node not in self.m:
                self.m[node] = node
                self.__root_cnt += 1

        root1 = self.getRoot(a)
        root2 = self.getRoot(b)
        if root1 != root2:
            self.m[root1] = root2
            self.__root_cnt -= 1

    def isInSameSet(self, a, b):
        for node in [a, b]:
            if node not in self.m:
                return False

        return self.getRoot(a) == self.getRoot(b)

    def getRootNum(self):
        return self.__root_cnt



class Solution:
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
        min_heap = PriorityQueue()

        for node1, node2, cost in pipes:
            min_heap.put((cost, node1, node2))
        for i, val in enumerate(wells):
            min_heap.put((wells[i], i+1, 0))

        merge_set = MergeSet()
        for i in range(n+1):
            merge_set.merge(i, i)

        edge_cnt = 0
        total_cost = 0
        while edge_cnt < n - 1:
            cost, node1, node2 = min_heap.get()
            if not merge_set.isInSameSet(node1, node2):
                merge_set.merge(node1, node2)
                total_cost += cost
                edge_cnt += 1
        return total_cost
```
