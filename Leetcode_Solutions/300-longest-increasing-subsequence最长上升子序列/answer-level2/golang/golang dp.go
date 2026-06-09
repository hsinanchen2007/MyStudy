### 解题思路
dp[i]定义为以nums[i]为结尾的最长上升子序列长度
[10] //longest = 1, dp[0]=[10]’len
[10 9] //longest = 1, dp[1]=[9]' len
[10 9 2] //longest = 1, dp[2]=[2]'len
[10 9 2 5] //longest = 2, dp[3]=[2 5]'len
[10 9 2 5 3] //longest = 2, dp[4] = [2 3]'len
[10 9 2 5 3 7] //longest = 3, dp[5] = [2 3 7]'len
[10 9 2 5 3 7 101] //longest = 4, dp[6] = [2 3 7 101]'len
[10 9 2 5 3 7 101 18] //longest = 4, dp[7] = [2 3 7 18]'len

for j := i-1; j>=0;j-- {
    if nums[i] > nums[j] {
        dp[i] = max(dp[i], dp[j])
    }
}
dp[i] += 1

### 代码
执行用时 :4 ms, 在所有 Go 提交中击败了76.64%的用户
内存消耗 :2.4 MB, 在所有 Go 提交中击败了28.19%的用户

```golang
func lengthOfLIS(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    result := 1
    dp := make([]int, len(nums))
    dp[0] = 1
    for i := 1; i < len(nums); i++ {
        maxLastLIS := 0
        for j := i-1; j >= 0; j--{
            if nums[i] > nums[j]{
                maxLastLIS = max(dp[j], maxLastLIS)
            }
        }
        dp[i] = maxLastLIS+1
        result = max(result, dp[i])
    }
    return result
}

func max(a, b int) int {
    if a >= b {
        return a
    }else{
        return b
    }
}

```