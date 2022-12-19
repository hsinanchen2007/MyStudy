![image.png](https://pic.leetcode-cn.com/bd53f74e53b041f0ae68c3ab920aca8cbee1436a5f1ab0aae75e6b90c8a070a6-image.png)


```
class MergeSet:
    def __init__(self, init_list):
        self.m = {i:i for i in init_list}

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
    def earliestAcq(self, logs: List[List[int]], N: int) -> int:
        merge_set = MergeSet(range(N))
        logs.sort(key = lambda x : x[0])

        cnt = 0
        for time, a, b in logs:
            merge_set.merge(a, b)
            cnt += 1

            if merge_set.getRootNum() == 1:
                return time
        return -1
```
