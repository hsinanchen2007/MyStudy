- 11以下打表
- 跳过长度为偶数的回文数。必含因数11。
- 跳过以24568开头（也就是以24568结尾）的回文数，比如遇到41314，直接从70007、70107开始检查
```
class Solution(object):
    def primePalindrome(self, N):
        """
        :type N: int
        :rtype: int
        """
        if 1 <= N <= 11:
            return [0, 2, 2, 3, 5, 5, 7, 7, 11, 11, 11, 11][N]
        def isPrime(n):
            for i in xrange(3, int(n ** 0.5 + 1), 2):
                if n % i == 0:
                    return False
            return True

        def getPal(left_part):
            return int(str(left_part) + str(left_part)[:-1][::-1])

        l = len(str(N))
        left_part = int("1" + "0" * (l / 2)) #default when l is even
        if l % 2 == 1:
            left_part = int(str(N)[:(l + 1) / 2])
            if getPal(left_part) <= N:
                left_part += 1
        while True:
            if str(left_part)[0] in "24568":
                base = int(math.pow(10, (len(str(left_part)) - 1)))
                left_part = (left_part / base + 1) * base
                continue
            pal = getPal(left_part)
            if isPrime(pal):
                return pal
            left_part += 1
```
