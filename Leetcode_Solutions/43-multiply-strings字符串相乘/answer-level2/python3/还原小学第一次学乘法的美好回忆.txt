虽然实现“str(int(num1)*int(num2))”很方便快捷，但是还是有必要知道怎么做的，这里没有涉及任何int类型计算，还原小学课堂的原始体验。

小学一年级和三年级分别要背两个字典：
加法字典：{（加数1，加数2，上一步的进位）：（两数之和，进位）}
乘法字典：{（因数1，因数2）：乘积}

按照要求分别实现下面几个功能函数：
1. 两数相加；
2. 多个数字相加；
3. 多位数乘一位数；
4. 多位数乘多位数。

小学够讲好几节课。


```vim
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        add_result = {(str(i), str(j), str(c)): (str((i + j + c) % 10), str((i + j + c) // 10)) for i in range(10) for j in range(10) for c in range(2)}

        mul_result = {(str(i), str(j)): str(i*j).zfill(2) for i in range(10) for j in range(10)}

        def two_sum(num1: str, num2: str) -> str:
            max_len = max(len(num1), len(num2))
            num1, num2 = num1.zfill(max_len), num2.zfill(max_len)
            res, carry = '', '0'
            for str1, str2 in reversed(list(zip(num1, num2))):
                sum_tmp, carry = add_result[(str1, str2, carry)]
                res = sum_tmp + res
            res = carry + res if carry == '1' else res
            return res

        def n_sum(nums):
            res = '0'
            for num in nums:
                res = two_sum(res, num)
            return res

        def mul_num_bit(digits, digit):
            """
            Multiply multiple digits with one digit.
            :return: 
            """
            res, carry = '', '0'
            for bit in reversed(digits):
                mul_res = mul_result[(bit, digit)]
                mul_res = two_sum(mul_res, carry)
                carry, mul_tmp = mul_res[0], mul_res[1]
                res = mul_tmp + res
            res = carry + res if carry != '0' else res
            return res

        def two_multiply(num1: str, num2: str):
            res = []
            num2 = num2[::-1]
            for i in range(len(num2)):
                cur_mul = mul_num_bit(num1, num2[i]) + '0' * i
                res.append(cur_mul)
            res = n_sum(res)
            return '0' if set(res) == {'0'} else res

        return two_multiply(num1, num2)
```