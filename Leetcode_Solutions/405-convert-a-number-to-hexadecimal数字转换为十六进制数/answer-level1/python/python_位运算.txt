难点在负数补码和低四位的位运算
```
class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        rst = ""
        # generate num to cha dic
        num_dic = {}
        for i in range(10):
            num_dic[i] = str(i)
        for i in range(10, 16):
            num_dic[i] = str(chr(i + 87))

        # process non-positive num
        if num == 0:
            return "0"
        elif num < 0:
            num += 2 ** 32

        while num:
            item = (num & 15)
            rst = num_dic[item] + rst
            num = (num >> 4)
        return rst

```
