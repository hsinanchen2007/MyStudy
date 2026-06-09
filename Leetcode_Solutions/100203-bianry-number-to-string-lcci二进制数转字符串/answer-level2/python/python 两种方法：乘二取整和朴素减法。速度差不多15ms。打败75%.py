```
class Solution(object):
    def printBin(self, num):
        if not (0 <= num <= 1):
            return "ERROR"
        rev = ['0.']
        while num > 0:
            num *= 2
            if num >= 1:
                rev.append('1')
                num -= 1
            else:
                rev.append('0')
            if len(rev) > 33:
                return 'ERROR'
        return ''.join(rev)

    def printBin2(self, num):
        """
        :type num: float
        :rtype: str
        """
        if not (0 <= num <= 1):
            return "ERROR"
        i = 0.5
        rev = ["0."]
        while num > 0:
            if num >= i:
                rev.append('1')
                num -= i
            else:
                rev.append('0')
            i /= 2
            if len(rev) > 33:
                return 'ERROR'

        return ''.join(rev)
```
printBin用乘二取整。
printBin2是能减2^(-n)就填1，否则填0。
两个都是>32位就返回ERROR