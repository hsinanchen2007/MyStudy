```
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        dict={1:'I',5:'V',10:'X',50:'L',100:'C',500:'D',1000:'M',
              4:'IV',9:'IX',40:'XL',90:'XC',400:'CD',900:'CM'}
        s=''
        for i in [1000,900,500,400,100,90,50,40,10,9,5,4,1]:
            if num//i:
                s+=dict[i]*(num//i)
                num=num%i
        return s
```
