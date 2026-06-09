### 解题思路
暴力枚举 每次判断0是不是在串里面就ok了

### 代码

```python
class Solution(object):
    def getNoZeroIntegers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        for i in range(1,n):
            a = str(i)
            b = str(n-i)
            if '0' not in a and '0' not in b:
                return [a,b]
        
```