### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()
        n=len(s)
        maxnum=0
        i=0
        j=0
        while(i<=n-1 and j<=len(g)-1):
           
            if(s[i]<g[j]):
                i+=1
            else:
                maxnum+=1
                j+=1
                i+=1
        return maxnum
                

                

```