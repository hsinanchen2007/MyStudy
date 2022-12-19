![1.PNG](https://pic.leetcode-cn.com/c45a47edda0ac445e63bd70c31336cd9bf20e4ae16763084e22aa2e8b040c18b-1.PNG)

### 解题思路
因为问题描述中，一个等差数列的个数至少要3个，那么对于dp[n]满足，
dp[0] = dp[1] = 0

计算dp[i]的问题可以分解成计算加上第i个值所组成的等差数列个数+不加上第i个值所组成的等差数列个数
也就是：dp[i] = 加上第i个值所组成的等差数列个数 + dp[i-1]

### 代码
[leetcode-golang](https://github.com/laijinhang/leetcode-golang)
```golang
func numberOfArithmeticSlices(A []int) int {
    if len(A) < 3 {
        return 0
    }
    dp := make([]int, len(A) + 1)
    num := 0
    for p, q := 0, 2;q < len(A);q++ {
        num = 0
        if A[q] - A[q-1] == A[q-1] - A[q-2] {
            for num = 1;p > 0 && A[q] - A[q-1] == A[p] - A[p-1] ;p-- {
                num++ 
            } 
        }
        dp[q+1] = dp[q] + num
        p = q - 1
    }
    return dp[len(A)]
}
```