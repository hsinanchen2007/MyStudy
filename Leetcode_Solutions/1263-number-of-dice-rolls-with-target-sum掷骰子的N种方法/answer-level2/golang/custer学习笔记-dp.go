```go []
func numRollsToTarget(d int, f int, target int) int {
    mod := int((1e9)+7)
    dp := make([]int, target+1)
    dp[0] = 1
    for i := 0; i < d; i++ {
        ndp := make([]int, target+1)
        for j := 1; j <= f; j++ {
            for k := 0; k <= target-j; k++ {
                ndp[k+j] = (ndp[k+j]+dp[k])%mod 
            }
        }
        //fmt.Println(dp)
        dp = ndp
    }
    return dp[target]
}
```
```go []
func numRollsToTarget(d int, f int, target int) int {
    m := make(map[int]int)
    for j := 1; j <= f; j++ {
        m[j]++
    }
    for i := 1; i < d; i++ {
        m1 := make(map[int]int)
        for j := 1; j <= f; j++ {
            for k, v := range m {
                k1 := k + j
                if k1 > target {
                    continue
                }
                m1[k1] = (m1[k1] + v)%1000000007
            }
        }
        m = m1
    }
    return m[target]
}
```