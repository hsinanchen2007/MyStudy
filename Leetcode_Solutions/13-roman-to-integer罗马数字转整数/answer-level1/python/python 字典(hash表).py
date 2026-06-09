### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def romanToInt(self, item):
        """
        :type s: str
        :rtype: int
        """
        roman_dict, result = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}, 0
        for i in range(len(item) - 1):
            if roman_dict.get(item[i]) < roman_dict.get(item[i+1]):
                result -= roman_dict.get(item[i])
            else:
                result += roman_dict.get(item[i])
        return result + roman_dict.get(item[-1])
```