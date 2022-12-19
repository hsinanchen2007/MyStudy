### 解题思路
这要怎么短哈哈哈哈哈

### 代码

```python
class Solution(object):
    def toHexspeak(self, num):
        """
        :type num: str
        :rtype: str
        """
        res = ""
        for i in hex(int(num))[2:]:
            if i == '0': 
                res += 'O'
            elif i == '1': 
                res += 'I'
            elif i not in ['a','b','c','d','e','f']:
                return "ERROR"
            else:
                res += i.upper()
        return res

```