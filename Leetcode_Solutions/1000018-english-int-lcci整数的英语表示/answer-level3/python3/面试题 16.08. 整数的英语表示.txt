
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
        def f(i):
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
        for i in b:
            if num >= i:
                ans += f(num // i) + [b[i]]
                num %= i
        return ' '.join(ans + f(num))
```