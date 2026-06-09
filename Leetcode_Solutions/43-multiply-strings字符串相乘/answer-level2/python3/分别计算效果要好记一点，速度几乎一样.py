### 解题思路
```
for i in range(n1-1, -1, -1):
    for j in range(n2-1, -1, -1):
        prod = (ord(num1[i])-ord('0'))*(ord(num2[j])-ord('0'))
        digits[i+j] += prod // 10
        digits[i+j+1] += prod % 10
        

for i in range(n1 + n2 - 1, 0, -1):
    carry = digits[i] // 10
    digits[i] = digits[i] % 10
    digits[i - 1] += carry

```
### 代码

```python3
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return "0"
        n1 = len(num1)
        n2 = len(num2)
        digits = [0]*(n1+n2)
        for i in range(n1-1, -1, -1):
            for j in range(n2-1, -1, -1):
                prod = (ord(num1[i])-ord('0'))*(ord(num2[j])-ord('0'))
                sum_ = 0
                sum_ = prod + digits[i+j+1]
                digits[i+j] += sum_ //10
                digits[i+j+1] = sum_ %10
                

        # for i in range(n1 + n2 - 1, 0, -1):
        #     carry = digits[i] // 10
        #     digits[i] = digits[i] % 10
        #     digits[i - 1] += carry

        return ''.join([str(i) for i in digits]).lstrip('0')

                

```