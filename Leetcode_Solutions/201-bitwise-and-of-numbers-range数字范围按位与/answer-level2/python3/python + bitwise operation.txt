```python
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        flag = True
        ans = 0
        for i in range(32, -1, -1):
        
            if not flag:
                ans = ans << 1
            else:
                if (m & (1 << i)) != (n & (1 << i)):
                    flag = False
                    ans = ans << 1
                else:
                    ans = (ans << 1) | (m & (1 << i) == 1 << i)
            
        return ans

```