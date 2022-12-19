### 解题思路
Python3 分解后数值分析

### 代码

```python3
# https://leetcode-cn.com/problems/fraction-addition-and-subtraction/
class Solution:
    def fractionAddition(self, expression: str) -> str:
        def gcd(a, b):
            while a != 0:
                a, b = b % a, a
            return b

        def lcm(a, b):
            return a * b // gcd(a, b)

        def num_analysis(num_str):
            minus = False
            num_str_no_sign = num_str
            if num_str[0] == '-':
                minus = True
                num_str_no_sign = num_str[1:]
            elif num_str[0] == '+':
                num_str_no_sign = num_str[1:]
            numerator, denominator = [int(n) for n in num_str_no_sign.split('/')]
            if numerator == 0:
                return '0/1', False, 0, 1, 0.0
            num_gcd = gcd(numerator, denominator)
            nums_value = -numerator / denominator if minus else numerator / denominator
            if num_gcd == 1:
                return '-' * minus + num_str_no_sign, minus, numerator, denominator, nums_value
            else:
                numerator, denominator = numerator // num_gcd, denominator // num_gcd
                return '-' * minus + str(numerator) + '/' + str(denominator), minus, numerator, denominator, nums_value

        sign_pos_list = [0]
        for i in range(1, len(expression)):
            if expression[i] == '+' or expression[i] == '-':
                sign_pos_list.append(i)
        sign_pos_list.append(len(expression))
        if len(sign_pos_list) == 1:
            return num_analysis(expression)[0]
        num_list = [expression[sign_pos_list[i]:sign_pos_list[i + 1]] for i in range(len(sign_pos_list) - 1)]
        num_analysis_list = [num_analysis(num) for num in num_list]
        res_value = sum(i[-1] for i in num_analysis_list)
        final_denominator = 1
        for i in num_analysis_list:
            final_denominator *= i[-2]
        final_numerator = round(res_value * final_denominator)
        if final_numerator == 0:
            return '0/1'
        final_numerator, final_denominator = abs(final_numerator), abs(final_denominator)
        final_str = '-' * (res_value < 0) + str(final_numerator) + '/' + str(final_denominator)
        return num_analysis(final_str)[0]


```