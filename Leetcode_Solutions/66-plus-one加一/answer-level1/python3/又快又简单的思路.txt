#### 思路
把数字从数组中还原，再+1，再重新转换为数组
只用到很简单的数字数位分解
#### 代码
```
class Solution(object):
    def plusOne(self, digits):
        power = 1
        num = 0
        one_plus = []
        lens = len(digits)
        for i in range(lens):
            num += digits[lens-1-i] * power
            power *= 10
        num += 1
        while num > 0:
            one_plus.append(num % 10)
            num = num // 10
        one_plus.reverse()
        return one_plus
```
