```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        num1, num2 = num1[::-1], num2[::-1]
        if len(num1) > len(num2): num1, num2 = num2, num1
        res = [0] * 230
        for i in range(len(num1)):
            carry = 0
            for j in range(len(num2)):
                mul_ans = int(num1[i]) * int(num2[j]) + carry
                carry, temp_res = mul_ans // 10, mul_ans % 10
                res[i + j ] += temp_res
            if carry != 0:
                res[i + len(num2)] += carry
        for i in range(222):
            if res[i] >= 10:
                res[i + 1] += res[i] // 10
                res[i] = res[i] % 10
        res_str = ''.join(map(str, res))
        res_str = res_str.rstrip('0')
        return res_str[::-1] if res_str != '' else '0'
```