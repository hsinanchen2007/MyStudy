### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def __init__(self):
        self.res=0
    def largestRectangleArea(self, l):
        if len(l)==0:return 0
        if min(l)==max(l):return l[0]*len(l)
        self.find(l,0,len(l)-1)
        return self.res
    def find(self,l,i,j,iter=0):
        mi=l[i:j+1].index(min(l[i:j+1]))+i
        self.res=max(self.res,l[mi]*(j-i+1))
        if mi-1>i:self.find(l,i,mi-1,iter+1)
        elif mi-1==i:self.res=max(self.res,l[i])
        if j>mi+1:self.find(l,mi+1,j,iter+1)
        elif mi+1==j:self.res=max(self.res,l[j])

```