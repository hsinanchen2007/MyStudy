```
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        l1 , l2 = len(num1) - 1 , len(num2) - 1
        ans = ''
        carry , tmp = 0 , 0
        while l1 >= 0 or l2 >= 0:
            tmp = int(num1[l1] if l1 >= 0 else 0) + int(num2[l2] if l2 >= 0 else 0) + carry
            if tmp > 9:
                carry = 1
                tmp -= 10
            else:
                carry = 0
            ans =  str(tmp) + ans
            l1 -= 1
            l2 -= 1
        return str(1) + ans if carry else ans
```
不知道求余、整除 操作和加减操作那个快？我都用了加减操作。