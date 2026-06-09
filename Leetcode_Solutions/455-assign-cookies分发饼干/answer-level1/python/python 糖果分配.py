### 解题思路
贪心算法，从小的开始满足，满足一个再搞下一个

### 代码

```python
class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int] 孩子的胃口
        :type s: List[int] 饼干大小
        :rtype: int
        """
        g=sorted(g)
        s=sorted(s)
        child=0
        cookie=0
        while(child<len(g) and cookie<len(s)):
            if(g[child]<=s[cookie]):
                child+=1
            cookie+=1
        return child

```