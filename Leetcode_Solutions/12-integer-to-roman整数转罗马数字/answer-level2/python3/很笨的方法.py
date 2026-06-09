### 解题思路


### 代码

```python3
class Solution:
    def intToRoman(self, num):
        d = {1:'I',5:'V',10:'X',50:'L',100:'C',500:'D',1000:'M',4:'IV',40:'XL',400:'CD',9:'IX',90:'XC',900:'CM'}
        s = ''
        for i in range(len(str(num))):
            a = num % 10
            num //= 10
            # b = a-5
            if a <= 5 or a == 9:
                s = d[a*(10**i)] + s if a in d.keys() else a*d[10**i] + s
            else:
                b = a - 5
                s = d[b*(10**i)] + s if b in d.keys() else b*d[10**i] + s
                s = d[5*(10**i)] + s
        return s
```