### 解题思路
1. 构造roman字符合值的转化map
2. 依次遍历每一个字符，加到result上，如果后面一个大于前面的数值，说明是小数前置，需要将当前值置为负值

### 代码

```python
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman_num_map = { 
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        result = 0
        for i in range(len(s)):
            num_i = roman_num_map.get(s[i])
            if not num_i:
                raise Exception('不支持的罗马符号'.format(s[i]))
            if i < len(s) - 1 and roman_num_map.get(s[i]) < roman_num_map.get(s[i + 1]):
                num_i = -num_i
            result += num_i
        return result


```