### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def merge(self, l, m, r, n):
        m-=1 ;n-=1
        for i in range(len(r)):
            tmp=r[i]
            while m+i>=0 and l[m+i]>tmp:
                l[m+i+1]=l[m+i]
                i-=1
            l[m+i+1]=tmp
        return l
            
```