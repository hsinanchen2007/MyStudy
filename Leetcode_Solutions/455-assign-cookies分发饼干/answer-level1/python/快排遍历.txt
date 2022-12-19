# 先用快排获得饼干和胃口的从小到大排序
`g.sort()``s.sort()`
# 然后从胃口开始遍历，遇到刚好大于等于就让饼干的index+1
## 注意不要让饼干的index越界！

```
class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort()
        s.sort()
        res = 0
        j = 0
        for i in range(len(s)):
            if s[i]>=g[j]:
                res+=1
                j+=1
            if j == len(g):
                break
        return res
```