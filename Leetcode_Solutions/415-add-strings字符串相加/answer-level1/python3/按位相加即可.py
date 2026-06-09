用C的感觉在写python，见笑了
```
class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1 = num1[::-1]
        num2 = num2[::-1]
        len1,len2 = len(num1),len(num2)
        max = len1 if len1 > len2 else len2
        sum = ''
        carry = 0
        for i in range(max):
            fir = int(num1[i]) if i<len1 else 0
            sec = int(num2[i]) if i<len2 else 0
            add = (fir+sec+carry)%10
            carry = int((fir+sec+carry)/10)
            sum += str(add)
        if carry > 0: sum += str(carry)
        if sum == '': return 0
        return sum[::-1]
```