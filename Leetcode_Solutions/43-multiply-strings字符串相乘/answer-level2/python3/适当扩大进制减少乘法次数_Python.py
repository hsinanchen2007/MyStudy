既然我们可以用十六进制表示二进制数，那此题也就可以用更大的进制来计算，可以大幅减少乘法次数。
如果使用32位数字，进制可以为10^4，相对10进制，乘法次数最多可以减少到原来的1/16
如果使用64位数字，进制可以为10^9，相对10进制，乘法次数最多可以减少到原来的1/81
如下是使用10000进制的python代码：

```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if not num1 or not num2 or num1[0] == '0' or num2[0] == '0': return '0'
        nums = [[], []]
        for i, num in enumerate([num1, num2]):
            while True:
                num, sub = num[:-4], num[-4:]
                nums[i].append(int(sub))
                if not num: break
        n1, n2 = len(nums[0]), len(nums[1])
        result, product = '', [0] * (n1 + n2)
        for i in range(n1):
            for j in range(n2):
                product[i + j] += nums[0][i] * nums[1][j]
        for i in range(1, n1 + n2):
            product[i] += product[i - 1] // 10000
            product[i - 1] = product[i - 1] % 10000
        for i in range(n1 + n2 - 1, -1, -1):
            if not result or '0' == result: result = str(product[i])
            else: result += '%04d' % product[i]
        return result
```
