```
class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        kids=len(g)
        g.sort()
        s.sort()
        count=0
        j=0
        # 每次都将最小尺寸的饼干给未分配的胃口最小的孩子
        for i in range(0,len(s)):
            if j<kids and s[i]>=g[j]:
                count+=1
                j+=1
        return count
```
