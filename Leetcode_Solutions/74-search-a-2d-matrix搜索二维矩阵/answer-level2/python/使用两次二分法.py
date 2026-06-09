### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def searchMatrix(self, l, t):
        if len(l)==0 or len(l[0])==0:return False
        m,n=len(l),len(l[0])
        tmp=[]
        for i in l:
            tmp.append(i[-1])
        r=self.find(tmp,t)
        if tmp[r]<t:
            if r+1<=m-1:return l[r+1][self.find(l[r+1],t)]==t
            else:return False
        elif tmp[r]>t:
            return l[r][self.find(l[r],t)]==t
        else:return True
    def find(self,l,t):
        i=0 ;j=len(l)-1
        while i<j:
            m=(i+j)//2
            if l[m]<t:
                i=m+1
            elif l[m]>t:
                j=m-1
            else:return m
        return i
```