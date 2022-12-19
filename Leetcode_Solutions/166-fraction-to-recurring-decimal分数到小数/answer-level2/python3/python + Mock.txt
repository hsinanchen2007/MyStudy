```python
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        #    numerator
        #   ------------
        #    denominator
        # 1 / 3 => 0
        # corner case numerator == 0
        flag = numerator * denominator
        if flag == 0: return '0'
        numerator, denominator = abs(numerator), abs(denominator)
        res = ''
        res += self.getInteger(numerator, denominator)
        numerator = numerator % denominator * 10
        if numerator != 0:
            res += '.' + self.getPointer(numerator, denominator)
        if flag < 0 : res = '-' + res
        return res

    def getInteger(self, a, b):
        return str(a // b)
    
    def getPointer(self, a, b):
        # a = 10, b = 3
        res = ''
        hash_table = collections.defaultdict(int)
        # [10: 0]
        # res = '3' a = 10
        i = 0
        while True:
            if a % b == 0:
                res += str(a // b)
                break
            if a in hash_table:
                index = hash_table[a]
                res = res[: index] + '(' + res[index:] + ')'
                break
            hash_table[a] = i
            res += str(a // b)
            a = a % b * 10
            i += 1
        return res
```