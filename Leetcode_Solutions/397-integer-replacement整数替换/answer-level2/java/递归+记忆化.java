### 解题思路
定义状态dp[i]为将i替换为1所需的最少次数。如果n为偶数，则它只能由n/2转化而来，所以dp[n] = dp[n/2]+1；如果n为奇数，则有两种可能，一个是由前一个数转化而来，即dp[n-1]+1，另一个是由后一个数转化而来，即dp[i+1]+1。由于尝试开辟大小为n的int型数组时超出内存限制，所以采用HashMap数据结构存储中间状态，避免无用的重复计算。另外，注意超出int型数据范围的情况。

其实本段代码可不用递归的形式，改写成纯动态规划的形式。

### 代码

```java
class Solution {

    private Map<Long, Integer> dp = new HashMap<>();

    public int integerReplacement(long n) {
        if (n < 4) {
            return (int) n - 1;
        }

        if (dp.get(n) != null) {
            return dp.get(n);
        }

        int result = 0;
        if (n % 2 == 0) {
            result = integerReplacement(n / 2) + 1;
        } else {
            result = Math.min(integerReplacement(n - 1), integerReplacement(n + 1)) + 1;
        }
        dp.put((long) n, result);
        return result;
    }
}
```