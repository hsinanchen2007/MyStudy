### 解题思路
dp 公式, 2个状态，0 表示不抢，1表示抢
dp[0, 0] = 0
dp[0, 1] = nums[0]
dp[i, 0] = max(dp[i - 1, 0], dp[i - 1, 1])
dp[i, 1] = nums[i] + dp[i - 1, 0]
返回最后一个dp最大值
优化：用两个变量就可以满足，替换dp数组

### 代码

```golang
典型的动态规划问题，第一次用贪心解答错了，经过详细分析终于解决

func rob(nums []int) int {
    l := len(nums)
    if l == 0 {
        return 0
    }
    if l == 1 {
        return nums[0]
    }

    non := 0
    rob := nums[0]

    for i := 1; i < len(nums); i++ {
        newRob := non + nums[i]
        tmp := non
        if rob > non {
            tmp = rob
        }
        non = tmp
        rob = newRob
    }
    if non > rob {
        return non
    }
    return rob
}
```