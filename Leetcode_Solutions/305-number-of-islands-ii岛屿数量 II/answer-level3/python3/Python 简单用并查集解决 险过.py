![image.png](https://pic.leetcode-cn.com/db003e36e206d4a944cb00f33127b034b666333611dfd906d60d7f79d28f534e-image.png)


```
from typing import List

'''
并查集应用，连在一起的节点用并查集归并在一起，每次添加陆地后
更新并查集根节点个数即可
'''

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
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        merge_set = MergeSet()

        ans = []
        all_pos = set()
        for i, j in positions:
            merge_set.merge(i*n + j, i*n + j)
            all_pos.add((i, j))

            for ii, jj in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                if ii >= 0 and ii < m and jj >= 0 and jj < n and (ii, jj) in all_pos:
                    merge_set.merge(i*n + j, ii*n + jj)

            ans.append(merge_set.getRootNum())

        return ans
```
