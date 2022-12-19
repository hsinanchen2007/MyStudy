### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        result = int(''.join(reversed(list(str(abs(x))))))
        co = 0 if result> 2147483647 else result
        return co if x > 0 else -co
```