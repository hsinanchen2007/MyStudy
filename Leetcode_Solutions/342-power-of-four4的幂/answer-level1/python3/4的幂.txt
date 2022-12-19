### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        while True:
            rest = num 
            if num % 4 == 0:
                num //= 4
            if num == 1:
                return True
            if rest == num:
                return False
```