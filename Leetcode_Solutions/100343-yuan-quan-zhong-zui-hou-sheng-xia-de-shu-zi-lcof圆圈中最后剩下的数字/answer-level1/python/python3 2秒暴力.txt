### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        if m==1:
            return n-1
        l=list(range(n))
        i=0
        while n>1:
            i=(m+i-1)%n
            l.pop(i)
            n-=1
            if i==n:
                i=0
        return l[0]


```