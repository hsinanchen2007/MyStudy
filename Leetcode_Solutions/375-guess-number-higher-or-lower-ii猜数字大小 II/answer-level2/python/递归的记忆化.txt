暴力法的递归过程因为重复的访问了一些节点造成了空间和时间的浪费，直接采用字典存储这些节点，将方便后续的递归。


```
class Solution:
    def getMoneyAmount(self, n: int) -> int:
        self.ret = collections.defaultdict(list)
        def xunzhao(a, b):
            if a >= b:
                return 0
            if self.ret[(a,b)]:
                return self.ret[(a,b)]
            m = float('inf')
            for i in range((a+b)//2, b):
                res = i + max(xunzhao(a, i-1), xunzhao(i+1, b))
                m = min(m, res)
            self.ret[(a,b)] = m
            return m
        return xunzhao(1, n)
```




