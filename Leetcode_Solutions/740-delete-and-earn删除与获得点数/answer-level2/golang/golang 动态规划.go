
```golang
func deleteAndEarn(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    sort.Ints(nums) 
    max := nums[len(nums)-1] 

    al, dp := make([]int, max+1), make([]int, max+1)
    for i:= range nums{
        al[nums[i]]++
    }

    dp[1] = al[1] 

    for i:=2; i <=max;i++ {
        dp[i] = Max(dp[i-2]+ al[i]*i, dp[i-1])
    } 
    return dp[max]
}

// 3 4 2 
// 0 0 1 1 1 
func Max(i,j int)int {
    if i > j {
        return i
    }
    return j
}
```