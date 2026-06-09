执行用时：0 ms，在所有golang提交中击败了100.00%的用户

正常的*minimax*，直接递归的话时间上会比较菜，所以优化了一下：

1. 序列长度为偶数时，先手必胜，因为此时先手可以保证自己一定拿到奇数位所有数或者偶数位所有数，而对手则会拿到剩下的序列；
2. 加了个粗糙的dp矩阵，用来记录已经计算的结果，空间换时间。

ps. Go中切片默认是引用传参，所以在递归时使用切片不会增大额外的空间复杂度。

```go
func maxi(nums []int, dp [][]int, i int, j int) int {
    if i > j {
        return 0
    }
    if i == j {
        return nums[i]
    }
    if dp[i][j] != 0 {
        return dp[i][j]
    }
    left := mini(nums, dp, i + 1, j) + nums[i]
    right := mini(nums, dp, i, j - 1) + nums[j]
    if left >= right {
        dp[i][j] = left
        return left
    } else {
        dp[i][j] = right
        return right
    }
}

func mini(nums []int, dp [][]int, i int, j int) int {
    if i > j {
        return 0
    }
    if i == j {
        return 0 - nums[0]
    }
    if dp[i][j] != 0 {
        return 0 - dp[i][j]
    }
    left := maxi(nums, dp, i + 1, j) - nums[i]
    right := maxi(nums, dp, i, j - 1) - nums[j]
    if right >= left {
        dp[i][j] = 0 - left
        return left
    } else {
        dp[i][j] = 0 - right
        return right
    }
}

func PredictTheWinner(nums []int) bool {
    n := len(nums)
    if n % 2 == 0 {
        return true
    }
    var dp [][]int
    dp = make([][]int, n)
    for i := 0; i < n; i++ {
        dp[i] = make([]int, n)
    }
    return maxi(nums, dp, 0, n - 1) >= 0;
}
```