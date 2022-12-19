### 解题思路
此处撰写解题思路
观察题目可以发现排列顺序正好是树的后序遍历顺序
### 代码

```python
from copy import deepcopy as dc
import math
class Solution(object):
    def __init__(self):
        self.i=0 ;self.res=None
    def getPermutation(self,n,k):
        d=k//math.factorial(n-1)+1
        k=k%math.factorial(n-1)
        if k==0:
            d-=1;k=math.factorial(n-1)
        self.res=[d]
        self.find(n,k,[d])
        s=''
        for i in self.res:
            s+=str(i)
        return s
    def find(self,n,k,q):
        if self.i>=k:return
        if len(q)==n:
            self.i+=1
            if self.i==k:
                self.res=dc(q)
            return
        for i in range(1,1+n):
            if i not in q:
                q.append(i)
                self.find(n,k,q)
                q.pop()
```