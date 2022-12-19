![image.png](https://pic.leetcode-cn.com/96ccb799fffaa263258567bab389e8e551667ee6acf63f29d966deaf6db888d2-image.png)



```
'''
并查集应用，能够互相交换的位置翻到一个簇里面，同一个族中位置
对应的字符一定可以排序得到一个最小的子序列，每一个簇都进行
重拍，然后把排序后字符顺次放到簇里面的位置上，最后得到的
连接起来的字符串就是字典序最小的
'''

class MergeSet:
    def __init__(self):
        self.m = {}

    def getRoot(self, node):
        if node not in self.m:
            return node

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
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        merge_set = MergeSet()

        for a, b in pairs:
            merge_set.merge(a, b)

        n = len(s)
        m = {}
        for i in range(n):
            root = merge_set.getRoot(i)
            if root not in m:
                m[root] = []
            m[root].append(i)

        ans = ['' for _ in range(n)]
        for l in m.values():
            l.sort()
            sub_str_list = [s[idx]for idx in l]
            sub_str_list.sort()

            for idx, ch in zip(l, sub_str_list):
                ans[idx] = ch

        return ''.join(ans)
```
