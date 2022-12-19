![image.png](https://pic.leetcode-cn.com/b47147ac47e643ebb61ffaa1ab996fce347f9591e1dc9d784fd9748f68e544ae-image.png)

难度可以说没有，就是模拟分解数字，三位三位的分解就是了，就是测试数据和验证程序很有意思。

```python []
class Solution:
    def numberToWords(self, num: int) -> str:
        b = {1000000000: 'Billion', 1000000: 'Million', 1000: 'Thousand'}
        d = {100: 'Hundred', 90: 'Ninety', 80: 'Eighty', 70: 'Seventy',
            60: 'Sixty', 50: 'Fifty', 40: 'Forty', 30:'Thirty', 20: 'Twenty',
            19: 'Nineteen', 18: 'Eighteen', 17: 'Seventeen', 16: 'Sixteen',
            15: 'Fifteen', 14: 'Fourteen', 13: 'Thirteen', 12: 'Twelve',
            11: 'Eleven', 10: 'Ten', 9: 'Nine', 8: 'Eight', 7: 'Seven', 6: 'Six',
            5: 'Five', 4: 'Four', 3: 'Three', 2:'Two', 1: 'One', 0: 'Zero'}
        if num < 100 and num in d:
            return d[num]
        def f(i):           #三位数及以下的处理函数
            res = []
            if i >= 100:
                res += [d[i // 100], d[100]]
                i %= 100
            if i > 20:
                res += [d[i // 10 * 10]]
                i %= 10
            if i > 0:
                res += [d[i]]
            return res
        ans = []
        """#负数时的判定方法
        if num < 0:
            ans += ['Negative']
            num *= -1
        """
        for i in b:
            if num >= i:    #三位一组分割数字
                ans += f(num // i) + [b[i]]
                num %= i
        return ' '.join(ans + f(num))
```


明明说了是非负整数，但是系统却可以通过负数的测试，小数和超容则都通不过。

![image.png](https://pic.leetcode-cn.com/7bcdf2b2c07e4d47f6b23f82182ef20ae2b2ef64e4f2044aa8ed770fd2d561c0-image.png)
