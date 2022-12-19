### 解题思路
中规中矩的逐位相乘、逐行相加

### 代码

```python3
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return '0'

        def getmul(c1, c2, carry):#处理带进位的两字符相乘
            ans = str((ord(c1)-ord('0'))*(ord(c2)-ord('0')) + ord(carry)-ord('0'))
            return ans if len(ans)==2 else '0'+ans

        def getadd(num1, num2):#处理两整数相加
            from itertools import zip_longest
            ans, carry = '', '0'
            for c1, c2 in zip_longest(num1[::-1], num2[::-1], fillvalue = '0'):
                tmp = str(ord(c1) + ord(c2) + ord(carry) - 3*ord('0'))
                ans = tmp[-1] + ans
                carry = tmp[0] if len(tmp)>1 else '0'
            return carry+ans if carry!='0' else ans 

        if len(num2)<len(num1):
            num1, num2 = num2, num1 
        ans = start = ''
        for s in num1[::-1]:
            carry, tmp = '0', ''
            for t in num2[::-1]:
                carry, res = getmul(s, t, carry)
                tmp = res + tmp
            tmp = carry + tmp if carry!='0' else tmp
            ans = getadd(ans, tmp + start)
            start += '0'
        return ans
        
```