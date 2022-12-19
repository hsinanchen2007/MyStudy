用了非常蠢的方法，如果一个数n是超级回文数，那么它的平方根也是回文数，先找出sqrl(L)到sqrt(R)之间所有的回文数，再判断其平方是不是回文数。L和R上限是10^18，sqrt(L)和sqrt(R)上限是10^9，其中回文数的数量不超过9*10^4+9*10^3+9*10^3+……个，这个数量不是特别多，遍历一遍就ok了。
在找到sqrt(L)和sqrt(R)之间的回文数时，为了省事，直接找出所有的字符长度为sqrt(L)到sqrt(R)之间的所有回文数，然后要多判断一下是不是在sqrt(L)和sqrt(R)之间，简单粗暴。不得不说这个方法很蠢，但是勉勉强强通过了。

```
from math import sqrt, floor, ceil


class Solution:
    def superpalindromesInRange(self, L: str, R: str) -> int:
        L, R = int(L), int(R)
        sqrtl, sqrtr = int(ceil(sqrt(L))), int(floor(sqrt(R)))
        cnt = 0
        palidromes = self.palindromesInRange(str(sqrtl), str(sqrtr))
        # print(palidromes)
        for a in palidromes:
            val = int(a)
            if val >= sqrtl and val <= sqrtr and self.check(val * val):
                cnt += 1
        return cnt

    def palindromesInRange(self, L: str, R: str):
        lenl, lenr = len(L), len(R)
        L, R = int(L), int(R)
        res = []
        for length in range(lenl, lenr + 1, 1):
            self.palindromesFixedLength(['0'] * length, 0, res)
        return res

    def palindromesFixedLength(self, digits, i, res):
        if i == (len(digits) - 1) // 2:
            if i == 0:
                for char in '123456789':
                    digits[i] = char
                    digits[len(digits) - 1 - i] = char
                    res.append(''.join(digits))
            else:
                for char in '0123456789':
                    digits[i] = char
                    digits[len(digits) - 1 - i] = char
                    res.append(''.join(digits))
        else:
            if i == 0:
                for char in '123456789':
                    digits[i] = char
                    digits[len(digits) - 1 - i] = char
                    self.palindromesFixedLength(digits, i + 1, res)
            else:
                for char in '0123456789':
                    digits[i] = char
                    digits[len(digits) - 1 - i] = char
                    self.palindromesFixedLength(digits, i + 1, res)

    def check(self, number):
        string = str(number)
        l, r = 0, len(string) - 1
        while l < r:
            if string[l] != string[r]:
                return False
            else:
                l += 1
                r -= 1
        return True


# if __name__ == "__main__":
#     solution = Solution()
#     cnt = solution.superpalindromesInRange("43143", "7072263972576")
#     print(cnt)
```
