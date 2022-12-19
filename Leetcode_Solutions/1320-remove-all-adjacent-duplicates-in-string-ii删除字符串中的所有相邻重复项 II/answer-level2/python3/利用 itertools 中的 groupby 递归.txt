具体用法参见 [官方介绍](https://docs.python.org/zh-cn/3/library/itertools.html#itertools.groupby)

就是可以将连续相同的子序列分隔开：
```
[k for k, g in groupby('AAAABBBCCDAABBB')] --> A B C D A B
[list(g) for k, g in groupby('AAAABBBCCD')] --> AAAA BBB CC D
```
然后在进行递归：
```
from itertools import groupby
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        l = [list(k) for j,k in groupby(s)]
        m = [l[i] if len(l[i])<k else l[i][0]*(len(l[i])%k) for i in range(len(l))]
        if l == m:
            return ''.join([j[i] for j in l for i in range(len(j))])
        s = ''.join([j[i] for j in m for i in range(len(j))])
        return self.removeDuplicates(s,k)
```
最开始的时候写的 `m = list(filter(lambda x:len(x)!=k,l))` 然后发现如果比k大的时候有问题，又分是否为k的倍数，于是改成 `m = [l[i] if len(l[i])<k else l[i][0]*(len(l[i])%k) for i in range(len(l))]`

这样做每次都去除所有的重复 $k$ 个 $/k$ 倍数个子串，递归次数相对较少，但可能 groupby 的时候又耗时也说不好更快，
成绩：112 ms，在所有 Python3 提交中击败了 100.00% 的用户
