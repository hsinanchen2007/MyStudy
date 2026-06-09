### 解题思路
没有用什么算法，执行时间复杂度比较高

### 代码

```python
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        i = 0
        while True:
            if i*i < x:
                i += 1
            elif i*i == x:
                return int(i)
                break
            else:
                return int(i-1)
                break
                
                
            


        
```