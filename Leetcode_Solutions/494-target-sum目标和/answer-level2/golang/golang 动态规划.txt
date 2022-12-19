字典存当前和为某值的方法数
对每一个num in nums，都可以选择两种符号，每个选择都会使字典的键值对发生偏移，偏移两次后组成新字典
```
func findTargetSumWays(nums []int, S int) int {
    dp := make(map[int]int)
    if len(nums) == 0{
        dp[0] = 1
    }
    for i,v := range(nums){
        temp := make(map[int]int)
        if i == 0{
            dp[0+v] += 1
            dp[0-v] += 1
            continue
        }
        for sum,num := range(dp){
            temp[sum+v] += num
            temp[sum-v] += num
        }
        dp = temp
    }
    return dp[S]
}
```
