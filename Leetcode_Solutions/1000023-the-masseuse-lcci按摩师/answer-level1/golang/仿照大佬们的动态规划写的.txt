### 解题思路
此处撰写解题思路
长路漫漫~~
执行用时 :12 ms, 在所有 Go 提交中击败了100.00% 的用户
内存消耗 :2.4 MB, 在所有 Go 提交中击败了100.00%的用户
### 代码

```golang
func massage(nums []int) int {

    //先写边界 双指针有没有可能适合本题 前面推不行，试试中间和后面推，碰到最优啥的，考虑动态规划
    // 如果有递归的话，先写结束条件
    if len(nums) == 0 {
        return 0
    }
    if len(nums) == 1 {
        return nums[0]
    }
    if len(nums) == 2 {
        if nums[0] > nums[1] {
            return nums[0]
        }else {
            return nums[1]
        }
    }
    //动态规划
    var dp []int
    dp = append(dp, nums[0])
    dp = append(dp, nums[1])
    dp = append(dp, nums[0] + nums[2])
    for i := 3; i < len(nums); i++ {
        var max int
        if dp[i-2] > dp[i-3] {
            max = dp[i-2]
        }else {
            max = dp[i-3]
        }
        dp = append(dp, max + nums[i])
        fmt.Println(dp)
    }

    if dp[len(nums) - 1] > dp[len(nums) - 2] {
        return dp[len(nums) - 1]
    }else {
        return dp[len(nums) - 2]
    }
}
```