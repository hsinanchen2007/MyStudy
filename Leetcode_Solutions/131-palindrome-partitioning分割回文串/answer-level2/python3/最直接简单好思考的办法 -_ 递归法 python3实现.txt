我先思考了，如果用人在草纸上手动做的话，该怎么做。

对于字符串 `"aabb"` ，我们直接使用类似“枚举的思想”，对每个字符串中每个字符后进行一次分割：
- a|abb
- aa|bb
- aab|b
- aabb|

接着检查前半部分是否为回文，如果为回文，则对其后半部分再次进行分割，以a|abb为例：
- a|bb
- ab|b
- abb|

以此类推，如果能够抵达最后一个字符，则返回该数组，将其加入用于返回的数组。

这就是递归呀。

```python3 []
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def ispartition(sub):
            for i in range((len(sub) + 1) // 2):
                if sub[i] != sub[len(sub) - i - 1]:
                    return False
            return True

        rts = []
        def bfs(father, ss):
            if len(ss) == 0:
                rts.append(father)
                return
            for i in range(len(ss)):
                tmp = father.copy()
                upper = ss[:(i+1)]
                lower = ss[(i+1):]
                if ispartition(upper):
                    tmp.append(upper)
                    bfs(tmp, lower)
            return 0
        
        bfs([], s)
        return rts
```

刚刚开始刷 LeetCode ，第一次 Submit 就通过，通过这道题，我总结出了两条经验：
- 递归函数要把停止条件写在开头；
- 递归在什么时候用呢？**一个问题可以被拆分为多个子问题，且子问题与父问题是同一类问题时，使用递归正合适。**