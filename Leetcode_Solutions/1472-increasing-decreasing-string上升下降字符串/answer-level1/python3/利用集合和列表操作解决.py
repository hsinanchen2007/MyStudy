```
class Solution:
    def sortString(self, s: str) -> str:
#对于s取集合去重，将set(s)正向排序加入res，再把set(s)中出现过的元素从s中删除，再将剩下的s取集合去重，将set(s)反向加入res，再把出现过的元素从s中删除，循环执行直到s长度为0
        res = ''
        while len(set(s)) > 0:
            res += ''.join(sorted(set(s)))
            for c in set(s):
                s = s.replace(c, '', 1)
            res += ''.join(sorted(set(s))[::-1])
            for c in set(s):
                s = s.replace(c, '', 1)
        return res

```
