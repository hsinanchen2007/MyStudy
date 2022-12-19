我们可以将一个数字拆分为最高位和其右边 ，比如 3452，拆成 3 和 452， 最高位 high = 3, last = 452, 数的范围是几千的数字，那么 power = 1000  先看最高位贡献了多少个 1，如果最高位大于1、 那么最高位贡献1000个1，1000~1999  那么剩余位贡献多少个1呢，只要看0-999的个、十、百位贡献了多少个1， 那么 1000~1999，2000~2999， 的个、十、百位贡献的1的个数都是一样的 即high * countDigitOne(power-1)个1  最后还剩下3000-3452这last+1个数字的个、十、百位贡献的1的数量，即countDigitOne(last)

```python
class Solution(object):
    def countDigitOne(self, n):
        """
       用递归做的，可以改成记忆化搜索，加快时间
        """
        if n<=0: return 0
        if n<10: return 1
        last = int(str(n)[1:])
        power =  10**(len(str(n))-1)      
        high = int(str(n)[0])
        if high == 1:
            return self.countDigitOne(last) + self.countDigitOne(power-1) + last+1
        else:
            return power+high*self.countDigitOne(power-1) + self.countDigitOne(last);
```