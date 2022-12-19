### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def search(self,l,t):
        if len(l)==0:return False
        if t==l[0] or t==l[-1]:return True
        if l[-1]<t<l[0]:return False
        i=0 ;j=len(l)-1
        while i<j:
            m=(i+j)//2
            print(i,j,m)
            if self.judge(m,l,t):
                if l[m]>t:
                    j=m-1
                elif l[m]<t and t<l[-1]:
                    i=m+1
                elif l[m]<t and t>l[0]:
                    j=m-1
                else:return True
            else:
                if l[m]>t and t<l[-1]:
                    i=m+1
                elif l[m]>t and t>l[0]:
                    j=m-1
                elif l[m]<t:
                    i=m+1
                else:return True
        return l[j]==t or l[j]==t
    def judge(self,m,l,t):
        for i in range(m,len(l)-1):
            if l[i+1]<l[i]:return False
        return True
```