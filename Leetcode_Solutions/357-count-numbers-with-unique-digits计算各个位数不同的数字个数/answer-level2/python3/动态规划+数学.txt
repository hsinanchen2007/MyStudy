方法1：直接求出所有的前十位数的个数。
```
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        dp = [1, 10]
        i = 2
        tmp = 9
        while i <= 10:
            tmp *= (11-i)
            dp.append(dp[-1] + tmp)
            i += 1
        if n <= 10:
            return dp[n]
        return dp[-1]
```
dp空间复杂度优化：
```
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        dp = 10
        i, tmp = 2, 9
        while i <= n and i <= 10:
            tmp *= (11-i)
            dp += tmp
            i += 1
        return dp
```
dp的go版本：
```
func countNumbersWithUniqueDigits(n int) int {
    if n == 0 {
        return 1
    }
    dp, tmp := 10, 9
    for i := 2; i <= n && i <= 10; i++ {
        tmp *= 11-i
        dp += tmp
    }
    return dp
}
```



方法2：把前十位数的个数求出来放进数组，直接调用。
```
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        dp = [1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 8877691]
        if n <= 10:
            return dp[n]
        return dp[-1]
```

