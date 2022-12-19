 ```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        carry = 0
        i = len(a) - 1
        j = len(b) - 1
        sum1 = sum2 = 0
        while i>=0 or j>=0:
            if i>=0:
                sum1 = a[i]
                i -= 1
            else:
                sum1 = 0
            if j>=0:
                sum2 = b[j]
                j -= 1
            else:
                sum2 = 0
            
            tmp = int(sum1) + int(sum2) + carry
            if tmp >= 2:
                carry = 1
                res += str(tmp - 2)
            else:
                carry = 0
                res += str(tmp)
       
         
        if carry == 1:
            res +='1'
       
        return res[::-1] 
```
