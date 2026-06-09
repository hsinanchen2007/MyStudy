### 解题思路
先取余数，得到每个位的数字，然后直接进行判断即可

### 代码

```python3
class Solution:

    @staticmethod
    def getStrByNum(a, w):
        """
        :param a: 相应位的数字
        :param w: 是哪个位（个十百）(0，1，2)
        :return:
        """
        if a == 9:
            a = "CM" if w == 2 else ("XC" if w == 1 else "IX")
        elif a >= 5:
            a = "D" + "C" * (a - 5) if w == 2 else ("L" + "X" * (a - 5) if w == 1 else "V" + "I" * (a - 5))
        elif a == 4:
            a = "CD" if w == 2 else ("XL" if w == 1 else "IV")
        else:
            a = "C" * a if w == 2 else ("X" * a if w == 1 else "I" * a)
        return a

    def intToRoman(self, num: int) -> str:
        # num 范围 [1,3999]
        a1 = num % 10  # 个
        a2 = num // 10 % 10  # 十
        a3 = num // 100 % 10  # 百
        a4 = num // 1000 % 10  # 千
        # print(a1, a2, a3, a4)
        a4 = "M" * a4
        a3 = Solution.getStrByNum(a3, 2)
        a2 = Solution.getStrByNum(a2, 1)
        a1 = Solution.getStrByNum(a1, 0)

        # print(a4, a3, a2, a1)
        return a4 + a3 + a2 + a1

```