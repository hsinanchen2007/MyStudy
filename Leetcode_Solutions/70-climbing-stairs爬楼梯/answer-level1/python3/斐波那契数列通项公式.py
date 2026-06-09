### 解题思路
斐波那契数列通项公式

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:

        return int(1/(5**0.5)*(((1+(5**0.5))*0.5)**(n+1) - ((1-(5**0.5))*0.5)**(n+1)))
        
```