```
class Solution:
    def findNthDigit(self, n: int) -> int:
        index = 0
        while n - (9 * (10 ** index) * (index + 1)) > 0:
            n =  n - (9 * (10 ** index) * (index + 1))
            index += 1
        nums = (n // (index + 1)) + (10 ** index)
        n = n % (index + 1)
        if n ==  0:
            n = index + 1
            nums -= 1
        indexI = index - n + 2
        return int((nums % (10 ** indexI)) // (10 ** (indexI - 1)))
```

思路先找到 n 所在的数中
然后单独的取出来~
注意坑点：比如11
11 - 9 = 2
2 // 2 = 1
但是我们并不能要1
所以在后面判断n是否为0 然后对nums进行完善