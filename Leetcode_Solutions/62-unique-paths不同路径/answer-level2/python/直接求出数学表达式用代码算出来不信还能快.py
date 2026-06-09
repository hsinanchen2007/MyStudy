### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def uniquePaths(self, m, n):
        s=0
        if n==1:return 1
        for i in range(1,n):
            s=s+self.select(m,i)*self.select(n-2,i-1)
        return s
    def select(self,m,n):
        a=1 ;b=1
        for i in range(1,n+1):
            a=a*m ;b=b*i
            m-=1
        return a/b
```