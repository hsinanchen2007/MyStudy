>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：动态规划

状态定义：

dp[i]：以A[i]为结尾的等差数列的个数

状态转移：

（1）当i == 0或i == 1时，dp[i] = 0。

（2）当i >= 2时，dp[i] = i - tmp - 1，其中[tmp, i]能构成以A[i]为结尾的最长等差数列

时间复杂度是O(n)。空间复杂度是O(1)。

执行用时：1ms，击败91.61%。消耗内存：34.8MB，击败68.13%。

```java
public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int n, result = 0;
        if (null == A || (n = A.length) < 3) {
            return 0;
        }
        int dp = 0;
        for (int i = 2; i < n; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp++;
            } else {
                dp = 0;
            }
            result += dp;
        }
        return result;
    }
}
```

# 解法二：找规律

计算数组A中两个数的差值，对于某一段差值相等的序列，假设其差值长度为count，那么该序列能构成count \* (count + 1) / 2个等差子序列。

以题给示例[1, 2, 3, 4]进行说明，其差值数组为[1, 1, 1]，长度为3，能够构成3 \* 2 / 2 = 3个等差子序列。

时间复杂度是O(n)，其中n为数组A的长度。空间复杂度是O(1)。

执行用时：0ms，击败100.00%。消耗内存：37.1MB，击败5.38%。

```java
public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int n, result = 0;
        if (null == A || (n = A.length) < 3) {
            return 0;
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (A[i - 1] - A[i - 2] == A[i] - A[i - 1]) {
                count++;
            } else {
                result += count * (count + 1) / 2;
                count = 0;
            }
        }
        if (count != 0) {
            result += count * (count + 1) / 2;
        }
        return result;
    }
}
```