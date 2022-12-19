
### 代码

```golang
func countVowelPermutation(n int) int {
    mul := make([]int, 5) 
    dp := []int{1,1,1,1,1}
    for i:=1; i < n; i++ {
        mul[0] = dp[1] + dp[2] + dp[4]
        mul[1] = dp[0] + dp[2]
        mul[2] = dp[1] + dp[3]
        mul[3] = dp[2]
        mul[4] = dp[2] + dp[3] 

        for i := range dp {
            dp[i] = mul[i] 
            dp[i] %= 1000000007
        }
    }
    result := 0 

    for i := range dp {
        result += dp[i]
    }
    return result % 1000000007
                     
}
```