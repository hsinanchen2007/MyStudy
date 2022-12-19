### 解题思路
需要删除n-1次

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        ans = [i for i in range(n)]
        t = n
        p = -1
        for i in range(1, t):
            p = (p+m) % n
            ans.pop(p)
            p-=1
            n-=1
        return ans[0]
            
            
        
```