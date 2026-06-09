
一种最直接最朴素的解法是(与背包问题类似)：设置数组dp，dp[i]表示组成和为i的完全平方数的最少个数。

从1到n进行遍历：
    1. 如果当前数字$i$是完全平方数，`dp[i]`为$1$
    2. 否则，`dp[i] = min([dp[j]+dp[i-j] for j in range(1,i//2+1)])`
```
import math
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [i for i in range(n+1)]

        for i in range(2,n+1):
            rooting = int(math.sqrt(i))
            if rooting**2 == i:
                dp[i] = 1
            else:
                dp[i] = min([dp[j]+dp[i-j] for j in range(1,i//2+1)])
        return dp[n]
```
时间复杂度$O(n^2)$,没有意外，超时。

后来一想，上面的`[dp[j]+dp[i-j] for j in range(1,i//2+1)]`是没有必要的，因为数字$i$最终都要表示成完全平方数的和，所以可以定义数组$squares$，记录到当前位置所遇到的能开方的数字。然后替换上述语句为`dp[i] = min([dp[j]+dp[i-j] for j in squares])`即可。

```
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [i for i in range(n+1)]
        squares = [1]
        for i in range(2,n+1):
            rooting = int(math.sqrt(i))
            if rooting**2 == i:
                squares.append(i)
                dp[i] = 1
            else:
                dp[i] = min([dp[j]+dp[i-j] for j in squares])
        return dp[n]
```
时间复杂度 $O(log_2(n!))$?