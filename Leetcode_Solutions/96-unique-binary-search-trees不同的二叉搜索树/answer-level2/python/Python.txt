### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def numTrees(self, n):
        a=[0]*(n+1)
        a[0]=1
        a[1]=1
        for i in range(2,n+1):
            for j in range(0,i):
                a[i]+=a[j]*a[i-1-j]




        return a[n]
```