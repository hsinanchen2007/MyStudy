大概思路就是将list转化成整数，以方便进行计算，再转化回list
```
class Solution(object):
    def plusOne(self, digits):
        s = ''
        for i in digits:
            s = s + str(i)
        num = int(s)
        num += 1
        re = str(num)
        re = list(re)
        return map(int, re)
```
