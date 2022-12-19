### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def __init__(self):
        self.s=0
    def exist(self, l, t):
        m,n=len(l),len(l[0])
        for i in range(m):
            for j in range(n):
                if l[i][j]==t[0]:
                    self.find(i,j,l,t)
                if self.s==1:return True
        return False
    def find(self,i,j,l,t):
        m,n=len(l),len(l[0])
        d=[lambda i,j:[i+1,j] ,lambda i,j:[i,j-1] ,lambda i,j:[i-1,j] ,lambda i,j:[i,j+1]]
        c=[lambda i,j:i+1<m ,lambda i,j:j>0 ,lambda i,j:i>0 ,lambda i,j:j+1<n]
        q=[[i,j]] ;checked=dict()
        while len(q)>0:
            if len(q)==len(t):
                self.s=1
                return True
            a,b=q[-1]
            for j,k in zip(d,c):
                tmp=j(a,b)
                if tmp not in q and tmp not in checked.get(self.code(q),[]):
                    if k(a,b) and l[tmp[0]][tmp[1]]==t[len(q)]:
                        q.append(tmp)
                        break
            else:
                tmp=q.pop()
                if len(q)>0:
                    key=self.code(q)
                    if key in checked:
                        checked[key].append(tmp)
                    else:checked[key]=[tmp]
        return False
    def code(self,q):
        l=[]
        for i in q:
            for j in i:l.append(j)
        return tuple(l)
```