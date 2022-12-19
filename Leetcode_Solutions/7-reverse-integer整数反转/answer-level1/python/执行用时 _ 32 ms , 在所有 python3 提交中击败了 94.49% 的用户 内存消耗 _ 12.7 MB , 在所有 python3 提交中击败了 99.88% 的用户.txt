### 解题思路
看着还行

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if x == 0: return 0
        if x < 0:
            x = str(abs(x))
            x = -1 * int(x[::-1])
            
        else:
            if x > 0:
                x = str(x)
                x = int(x[::-1])
                
        if -2**31 <= x <= 2 **31-1:
            return x
        else:return 0
```