![image.png](https://pic.leetcode-cn.com/b449944b157e49ec7a84f6e53263bce6353e77e44c095a88dfac0035212d9579-image.png)


```
'''
分组数一样的用户全部排到一个列表中，同一个列表中的用于按照group的大小分割成子列表即可
'''


from typing import List
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        m = {}
        for i, val in enumerate(groupSizes):
            if val not in m:
                m[val] = []
            m[val].append(i)

        ans = []
        for g_size, l in m.items():
            s, e = 0, g_size
            while s < len(l):
                ans.append(l[s:e])
                s, e = e, e+g_size

        return ans
```
