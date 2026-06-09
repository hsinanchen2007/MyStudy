![TIM截图20200314155438.png](https://pic.leetcode-cn.com/f995bf57c963a5ad6868f4d6fd7395cf52f7db98882877647ef754556093c19a-TIM%E6%88%AA%E5%9B%BE20200314155438.png)

```
class Solution:
    def findNthDigit(self, n: int) -> int:
        if n+1 <= 10: return n
        tim = 1
        res = 0
        dif = tim * 9 * 10 ** (tim - 1)
        while n > dif:
            n -= dif
            res += 9 * 10 ** (tim - 1)
            tim += 1
            dif = tim * 9 * 10 ** (tim - 1)
        res += n//tim
        tmp = n % tim
        if tmp:
            res += 1
            return int(str(res)[tmp-1])
        else:
            return int(str(res)[-1])
```
