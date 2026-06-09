### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        l=list(range(n))
        j=0
        for i in range(n-1):
            j=(j+m-1)%(n-i)
            l.pop(j)
        return l[0]
        
            
        
```