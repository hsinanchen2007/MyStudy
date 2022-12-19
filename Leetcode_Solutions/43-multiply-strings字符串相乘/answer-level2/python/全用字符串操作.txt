## 思路:

模拟乘法过程

一个数和一个数相乘

可以转化为 一个数的每一位和另一个数相乘的,再把所有数相加

所以,这里有两个过程,

第一个,一位数和另一位数字符串相乘

第二个,多个字符串相加

注意点: 要注意控制好第一个相乘得到位数,不够用0填充;

## 代码

```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":return "0"
        i = len(num1) - 1
        
        def one_str_mul(a, b):
            return str(int(a) * int(b))

        def add_str(a, b):
            i = len(a) - 1
            j = len(b) - 1
            carry_digit = 0
            tmp_res = ""
            while i >= 0 or j >= 0 or carry_digit:
                tmp_a = 0
                tmp_b = 0
                if i >= 0:
                    tmp_a = int(a[i])
                if j >= 0:
                    tmp_b = int(b[j])
                all_a_b = tmp_a + tmp_b + carry_digit
                tmp_res += str(all_a_b % 10)
                carry_digit = all_a_b // 10
                i -= 1
                j -= 1
            return tmp_res[::-1]
        all_add = []
        num_zeros = 0
        while i >= 0:
            tmp = one_str_mul(num1[i], num2)
            tmp += "0" * num_zeros
            all_add.append(tmp)
            num_zeros += 1
            i -= 1
        ans = ""
        for t in all_add:
            ans = add_str(ans, t)
        return ans
```

