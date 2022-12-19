### 解题思路
牛顿法。。。当初的高数恐怕是都还给老师了;(

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        for i in range(x//2+1):
            if x < (i+1)**2:
                return i
                

      


```