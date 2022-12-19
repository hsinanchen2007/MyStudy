### 解题思路
1. 转成integer加1
2. 再转成list
### 代码

```python
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """

        value = ""
        digits = list(map(str, digits))
        for digit in digits:
            value += digit
        
        value = str(int(value) + 1)
        digits = []

        for char in value:
            digits.append(char)
  
        return digits
```