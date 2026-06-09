# 1. 字符串处理，暴力解法，时间空间复杂度击败低
```
class Solution:
    def is_number(self, strr):
        try:
            float(strr)
            return True
        except (TypeError, ValueError):
            return False

    def myAtoi(self, str: str) -> int:

        strs = re.split(" ", str)
        res = ""

        for num in strs:
            if num != '':
                break

        try:
            res += num[0] if num[0] in ["+", "-", "."] or self.is_number(num[0]) else res
        except:
            return 0

        for i in num[1:]:
            if self.is_number(i):
                res += i
            else:
                num = res
                break

        try:
            num = math.floor(float(num)) if self.is_number(num) else 0
        except Exception as e:
            num = 0

        return min(max(num, pow(-2, 31)), pow(2, 31) - 1)
```
1. 分割、逐字符判断、添加检测代码
2. 时间复杂度O(n)，空间复杂度O(1)


# 2. 正则一步到位，但时间空间复杂度击败仍低
```
class Solution:
    def myAtoi(self, s: str) -> int:
        INI_MAX = 2147483647
        INI_MIN = -2147483648

        str = str.lstrip()  # clear preceding whitespace
        num = int(*re.findall("^[\+\-]?\d+", str))
        return max(min(int(num), INI_MAX), INI_MIN)
```
1. 时间复杂度O(n)，空间复杂度O(1)
2. *的使用和Regex的使用很巧妙，int("")返回0
