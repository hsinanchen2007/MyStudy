### 解题思路
设置一个字典，将对应的数字设为键，值设置为罗马字母，然后存放到dict中，然后分别去寻找数字的每一位对应的罗马字母，然后再进行拼接

### 代码

```python
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        hashmap = {1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C', 500: 'D', 1000: 'M', 4: 'IV', 9: 'IX',
        40: 'XL', 90: 'XC', 400: 'CD', 900: 'CM', 20: 'XX', 30: 'XXX', 60: 'LX', 70: 'LXX', 80: 'LXXX',
        2: 'II', 3: 'III', 6: 'VI', 7: 'VII', 8: 'VIII', 200: 'CC',  300: 'CCC', 600: 'DC', 700: 'DCC',
        800: 'DCCC', 2000: 'MM', 3000: 'MMM'}

        y = 0
        length = len(str(num))
        res = []
        for i in range(length):
            y = num % 10 * 10 ** i
            num = num / 10
            if y > 0:
                value = hashmap.get(y)
                res.insert(0, value)
        return ''.join(res)
```