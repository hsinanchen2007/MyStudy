![image.png](https://pic.leetcode-cn.com/5070b9c5c58c9cda0f65635bee9558cd76a009e1dddeac58e6d57592665ecab5-image.png)


```
from typing import List

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


class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n-1:
            return -1

        merge_set = MergeSet()
        for i in range(n):
            merge_set.merge(i, i)

        for s, e in connections:
            merge_set.merge(s, e)

        return merge_set.getRootNum() - 1
```
