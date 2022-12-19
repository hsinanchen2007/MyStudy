### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        i=1
        ans = 0
        while i<=n:
            ans = (ans+m)%i
            i+=1
        return ans
```