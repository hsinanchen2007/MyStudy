

### 代码

```python
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        if num < 0: return None
    
        res = []
        i = 0
        while i <= num:
            res.append(bin(i).count('1'))
            i += 1
        
        return res
```