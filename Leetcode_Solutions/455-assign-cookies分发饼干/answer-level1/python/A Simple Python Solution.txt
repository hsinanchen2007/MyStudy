执行用时 :156 ms, 在所有 Python 提交中击败了99.79% 的用户
内存消耗 :13 MB, 在所有 Python 提交中击败了22.96%的用户

```
class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        s.sort()
        g.sort()
        count = 0
        i=0
        j=0

        while i<len(g) and j<len(s):

            if g[i] <= s[j]:
                count+=1
                i+=1
                j+=1
            else:
                j+=1
        return count

        
```
