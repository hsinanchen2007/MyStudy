指数每次循环都翻倍，向上逼近n。

class Solution(object):
    def myPow(self, x, n):
        
        if n <= 0 and x == 0:
            return None
        elif n == 0 or x == 1:
            return 1
        elif x == 0:
            return 0
        multi = 1
        res = self.power(x, n)
        multi *= res[0]
        while res[1] != 0:
            res = self.power(x, res[1])
            multi *= res[0]
        return multi

    def power(self, x, n):
        m = abs(n)
        count = 1
        x_pow = x
        while count <= m:
            count *= 2
            if count <= m:
                x_pow *= x_pow
            else:
                count /= 2
                break
        if n > 0:
            ans = [x_pow, n - count]
        else:
            ans = [1.0 / x_pow, n + count]
        return ans