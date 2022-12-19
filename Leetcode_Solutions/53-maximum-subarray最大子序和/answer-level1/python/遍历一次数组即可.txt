### 解题思路
此处撰写解题思路
### 代码

```python
class Solution(object):
    def maxSubArray(self, l):
        s=0 ;i=0 ;res=-float('inf') ;m=-float('inf')
        while i<len(l):
            m=max(m,l[i])
            s+=l[i]
            if s>0:
                i+=1
                res=max(res,s)
            else:
                i+=1
                s=0
        if res==-float('inf'):return m
        return res
```