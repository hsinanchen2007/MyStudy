### 解题思路
此处撰写解题思路

### 代码

```python
from collections import deque
class Solution(object):
    def movingCount(self, m, n, ma):
        res=1
        d=[lambda x,y:[x+1,y],lambda x,y:[x-1,y],lambda x,y:[x,y+1],lambda x,y:[x,y-1]]
        q=deque([[0,0]]) ;ed=[[0,0]]
        while len(q)>0:
            if len(q)==m*n:return
            cur=q.popleft()
            for k in d:
                i,j=cur ;a,b=k(i,j)
                if 0<=a<=m-1 and 0<=b<=n-1 and [a,b] not in ed and self.cul(a)+self.cul(b)<=ma:
                    q.append([a,b])
                    ed.append([a,b])
                    res+=1
        return res
    def cul(self,i):
        p=[]
        while i>0:
            p.append(i%10)
            i=i//10
        return sum(p)
```