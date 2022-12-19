### 解题思路
1. 第i个节点是否能够到达，取决于从0到i-1个节点是否有一个能跳到i节点
2. 所以，dp[i] = {dp[0] || .... || dp[i-1]}

### 代码

```golang
func canJump(nums []int) bool {
    if len(nums) <= 1 {
        return true
    }
    dp := make([]bool, len(nums))
    dp[0] = true

    for i := 1; i < len(nums); i++ {
        flag := false
        for j := 0; j < i; j++ {
            if dp[j] && nums[j] + j >= i {
                flag = true
                break
            }
        }
        dp[i] = flag
    }

    return dp[len(nums)-1]
}
```