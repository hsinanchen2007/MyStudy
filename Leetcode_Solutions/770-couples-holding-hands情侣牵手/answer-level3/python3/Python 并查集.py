![image.png](https://pic.leetcode-cn.com/f7044e79c7c509014e524c04b1fe3a07f8c0043080bb7d4cb1ddfde8f018cd00-image.png)


```

'''
每个人都会有一个分组号，如果挨着两个人不属于同一个分组，
两个分组之间就会有一条边关联，最后这种冲突关系一定会
形成多个环，要解决一个环的问题，需要环的节点个数减1次
操作，用并查集统计处在同一个冲突环中的节点数，累计
每一个环的操作次数
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



from typing import List
from collections import Counter
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        merge_set = MergeSet()

        for i in range(0, len(row), 2):
            g1, g2 = row[i] // 2, row[i+1] // 2
            print(g1, g2)
            merge_set.merge(g1, g2)

        root_cnt = Counter()
        for g in range(len(row) // 2):
            root = merge_set.getRoot(g)
            print(f'root = {root}')
            root_cnt[root] += 1

        ans = 0
        for cnt in root_cnt.values():
           ans += cnt-1
        return ans

print(Solution().minSwapsCouples([3,2,0,1]))
```
