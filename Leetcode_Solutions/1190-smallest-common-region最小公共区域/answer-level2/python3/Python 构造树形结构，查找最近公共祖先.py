![image.png](https://pic.leetcode-cn.com/c87a7188f9cf1abb4feaea683ba686e246060720ea80f73435b53f798bd37049-image.png)


```
'''
构造树形结构，查找两个节点的最近公共祖先即可
'''

from typing import List
class Solution:
    def findSmallestRegion(self, regions: List[List[str]], region1: str, region2: str) -> str:
        m = {}
        for reg in regions:
            for child in reg[1:]:
                m[child] = reg[0]

        parent = set()
        cur = region1
        parent.add(cur)
        while cur in m:
            cur = m[cur]
            parent.add(cur)

        cur = region2
        while cur not in parent and cur in m:
            cur = m[cur]
        return cur
```
