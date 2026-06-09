### 代码

```python3
class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        
        len_ = len(a)
        if len_ == 0: return []
        elif len_ == 0: return [0]

        ans = [1] * len_
        # forward
        accum = a[0]
        # traverse from 1 to n-1
        for i in range(1, len_):
            ans[i] = accum
            accum *= a[i]
    
        # reverse
        accum = a[-1]
        # # traverse from n-2 to 0
        for i in range(len_-2, -1, -1):
            ans[i] *= accum
            accum *= a[i]

        return ans 
        
```