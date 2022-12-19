罗马数字总计13种基本数值，每次减去当前可拆分的最大基本数值，并转换记录，直到十进制数为零

```
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        weight_dict = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000,
                            "IV": 4, "IX": 9, "XL": 40, "XC": 90, "CD": 400, "CM": 900}
        # 根据value大小倒序排序
        weight_dict = sorted(weight_dict.items(), key=lambda x: x[1], reverse=True)

        i = 0
        res = ''

        while num > 0:
            # 每次减去当前最大单元数值，不足最大基本数值，最大基本数值变小
            if num >= weight_dict[i][1]:
                num -= weight_dict[i][1]
                res += weight_dict[i][0]
            else:
                i += 1

        return res
```
