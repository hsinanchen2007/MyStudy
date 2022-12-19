### 代码

```python
class Solution(object):
    def cuttingRope(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 0
        if n == 2:
            return 1
        if n == 3:
            return 2
        result = 0
        max_value = [0] * (n+1)
        max_value[0] = 0
        max_value[1] = 1
        max_value[2] = 2
        max_value[3] = 3
        for i in range(4,n+1):
            result = 0
            for j in range(1,i/2+1):
                temp = max_value[j] * max_value[i-j]
                if temp > result:
                    result = temp
                max_value[i] = result
        return max_value[n] % 1000000007
```