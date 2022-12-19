### 解题思路
此处撰写解题思路
每一个点可跳多个点，而多个点又可以跳多个点所以所有的可能性是一颗树，采用层序遍历并把同一层中的最远位置排在最前面，走过的位置要标记一下以防重复
### 代码

```python
from collections import deque
class Solution(object):
    def jump(self,l):
        d=dict()
        if len(l)==1:return 0
        q=[[0,0,l[0]]]
        s=[0 for i in range(len(l))]
        while q:
            nq=[]
            for cur in q:
                for i in range(1,cur[2]+1):
                    if cur[1]+i<len(l)-1 and s[cur[1]+i]==0:
                        nq.append([cur[0]+1,cur[1]+i,l[cur[1]+i]])
                        s[cur[1]+i]=1
                    elif cur[1]+i==len(l)-1:
                        return cur[0]+1
            nq.sort(key=lambda x:x[1],reverse=True)
            q=nq
```