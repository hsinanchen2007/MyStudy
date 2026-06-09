### 解题思路
见代码

### 代码

```python3
class Solution:
    def numberOfSteps (self, num: int) -> int:
        ans = 0
        while num > 1:
            if num & 1 == 1:
                ans += 1
            num >>= 1
            ans += 1
        
        if num > 0:
            ans += 1

        return ans
```