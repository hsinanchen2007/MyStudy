### 解题思路
暴力模拟，各种情况考虑清楚。。。。。。

### 代码

```python3
import math
class Solution:
    def myAtoi(self, _str: str) -> int:
        
        digits = [str(x) for x in range(10)]
        
        MAX = int(math.pow(2, 31) - 1)
        MIN = int(- (MAX + 1))
        
        flag = False
        result = 0
        minus = False
        for char in _str:
            if char == " ":
                if not flag:
                    continue
                else:
                    break
            elif char == "-":
                if not flag:
                    minus = True
                    flag = True
                else:
                    break
            elif char == "+":
                if not flag:
                    flag = True
                else:
                    break
            elif char in digits:
                if not flag:
                    flag = True
                result = result * 10 + int(char)
                if minus and result >= MAX + 1:
                    return MIN
                if not minus and result >= MAX:
                    return MAX
            else:
                break
        
        if minus:
            return -1 * result
        else:
            return result
                    
```