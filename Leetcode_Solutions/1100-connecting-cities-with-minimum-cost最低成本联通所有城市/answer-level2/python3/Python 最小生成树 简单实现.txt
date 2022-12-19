![image.png](https://pic.leetcode-cn.com/9ecb5ad3bffcba1f4a6a147dcd2466b667ead47d06717dac85b6d4b40c316a40-image.png)



```
'''
最小生成树算法
'''


class MergeSet:
    def __init__(self):
        self.m = {}

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

        root1 = self.getRoot(a)
        root2 = self.getRoot(b)
        if root1 != root2:
            self.m[root1] = root2

    def isInSameSet(self, a, b):
        for node in [a, b]:
            if node not in self.m:
                return False

        return self.getRoot(a) == self.getRoot(b)

    def getRootNum(self):
        cnt = 0
        for key in self.m.keys():
            if self.m[key] == key:
                cnt += 1
        return cnt


from typing import List
class Solution:
    def minimumCost(self, N: int, connections: List[List[int]]) -> int:
        merge_set = MergeSet()
        s = set()
        connections.sort(key = lambda x : x[2])

        if len(connections) < N-1:
            return -1

        total_cost = 0
        for node1, node2, cost in connections:
            if not merge_set.isInSameSet(node1, node2):
                merge_set.merge(node1, node2)
                total_cost += cost
                s.add(node1)
                s.add(node2)

        return total_cost if  len(s) == N and merge_set.getRootNum() == 1 else -1
```
