直接遍历两个字符转，每位乘以当前位数的10的幂最后加在一起
```
class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num11,num22 = 0,0
        j,s = 1,1
        for i in num1:
            num11 += int(i)*(10**(len(num1)-j))
            j += 1
        for i in num2:
            num22 += int(i)*(10**(len(num2)-s))
            s += 1
        return str(num11 + num22)
```
时间复杂度*O(n+n)*
