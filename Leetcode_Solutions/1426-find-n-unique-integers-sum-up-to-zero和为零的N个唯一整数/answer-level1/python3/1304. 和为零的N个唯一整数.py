### 解题思路

### 代码

```python3
class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = []
        if n % 2:
            for i in range(-n//2+1, n//2+1): 
                ans.append(i)
        else:
            for j in range(-n//2, n//2+1): 
                ans.append(j)
            ans.remove(0)
        return ans 

        
```