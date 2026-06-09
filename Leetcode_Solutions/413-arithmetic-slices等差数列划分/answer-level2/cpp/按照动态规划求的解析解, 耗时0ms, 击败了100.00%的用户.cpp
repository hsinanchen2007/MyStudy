###
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.3 MB, 在所有 C++ 提交中击败了100.00%的用户
### 解题思路

第一步, 找到等差数列, 并且获得长度
第二步, 按照题目要求构造了状态转移方程 dp[n] = dp[n-1] + n - 2 (n>=3) (也可以通过观察获得)

很明显, 递归方程可以求的解析解: $dp(n) = \frac{1}{2} \{n^2 - 3n + 2\}$

之后,考虑一下数组中会存在若干个等差数列, 或者 只有一个等差数列, 或者没有等差数列的情况即可

### 代码

```cpp
class Solution {
public:
    /**
     * step1: find arithmetic
     *        N stands for the length of the arithmetic
     * step2:
     *              dp[n] = dp[n-1] + n - 2 (n>3) ;
     *              dp[3] = 1 ;
     *              dp(n) = 1/2 * n**2 - 3/2 * n + 1
     *
     * @param A
     * @return
     */
    int numberOfArithmeticSlices(vector<int> &A) {
        if (A.size() < 3) return 0;
        int sum = 0;
        int n = 0;
        for (int i = 1; i + 1 < A.size(); i++) {
            auto a = A[i] - A[i - 1];
            auto b = A[i + 1] - A[i];
            if (a == b) {
                if (n == 0) n = 3;
                else n += 1;
            } else if (a != b) {
                if (n >= 3) sum += dp(n);
                n = 0;
            }
        }
        if (n >= 3) sum += dp(n);
        return sum;
    }

    int dp(int n) {
        auto a = 0.5 * (n * n - 3 * n + 2);
        return int(a);
    }
};
```