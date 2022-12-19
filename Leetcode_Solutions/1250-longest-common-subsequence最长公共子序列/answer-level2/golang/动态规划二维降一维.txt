# 二维矩阵的动态规划

首先，我们定义dp[i][j]为text1前i个字符和text2前j个字符的最大公共子序列，那么：

1. 当 text1[i] == text2[j] 时 dp[i][j] = dp[i-1][j-1] + 1
2. 当 text1[i] != text2[j] 时 dp[i][j] = max(dp[i-1][j], dp[i][j-1])

根据定义，我们可以实现下面的代码：

```go
func longestCommonSubsequence(text1 string, text2 string) int {
    dp := make([][]int, len(text1)+1)
    for i := 0; i <= len(text1); i++ {
        dp[i] = make([]int, len(text2)+1)
    }

    for i := 1; i <= len(text1); i++ {
        for j := 1; j <= len(text2); j++ {
            if text1[i-1] == text2[j-1] {
                dp[i][j] = dp[i-1][j-1] + 1
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            }
        }
    }

    return dp[len(text1)][len(text2)]
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```

# 二维降一维

画一个二维矩阵来看看动态规划是怎么更新d[i][j]的：

![image.png](https://pic.leetcode-cn.com/41e2aa9d75fbab49fc567f8cf6494e2afa61cfc54c5b824b4e46c251bb3f8e9b-image.png)

纵轴是i，横轴是j，我们最终的目的是得到最后的值3

根据前面的定义，我们可以知道，dp[i][j] 的值，由 dp[i-1][j-1]、dp[i-1][j]、dp[i][j-1] 决定，那么在矩阵中的位置就是：

![image.png](https://pic.leetcode-cn.com/2068e2e652b0bd17b734dbfa73b667b9b8395830616c7bc93d9017cac9324bcf-image.png)

假如我们只用dp[j]一维数组代表二维矩阵dp[i][j]中某一行第j列的值，那么下图状态是在二维矩阵更新第4行前，dp[j]的值，此时dp[j]的值跟二维矩阵第3行的值是一样的：

![image.png](https://pic.leetcode-cn.com/1d4b4be824d2b2cd0cbcdb3244382358a50bd7c36c8106417533efb650f73383-image.png)

这就相当于在更新第四行前，即使我们不使用二维矩阵，只使用dp[j]，我们也可以知道 dp[3][j] 和 dp[3][j-1]，也就是左上和上方的值，开始更新第四行的时候，更新到dp[4][j]时，dp[4][j-1]的值已经被更新了，对应到一维dp[j]上时，意味着我们需要有一个变量 last 来记录dp[j-1]的值（dp[3][j-1]），防止被更新掉，这样等开始确定 dp[i][j] 时，需要的三个位置的值我们都已经知道，代码如下：

```go
func longestCommonSubsequence(text1 string, text2 string) int {
    dp := make([]int, len(text2)+1)

    for i := 1; i <= len(text1); i++ {
        last := 0
        for j := 1; j <= len(text2); j++ {
            tmp := dp[j] // tmp 记录的是二维dp矩阵正上方的值
            if text1[i-1] == text2[j-1] {
                dp[j] = last + 1 // last 记录的是二维dp矩阵左上方的值
            } else {
                dp[j] = max(tmp, dp[j-1])
            }
            last = tmp
        }
    }

    return dp[len(text2)]
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```