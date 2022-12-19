### 解题思路
和丑数类似

### 代码

```golang
// idx2, idx3, idx5 := 0,0,0
// dp[i] = min(dp[idx2]*2, dp[idx3]*3, dp[idx5]*5)
// min选中哪个idx,则该idx++

func getKthMagicNumber(k int) int {
    if k == 0 {
        return 1
    }
    dp := make([]int,k)
    dp[0] = 1
    index3,index5,index7 := 0,0,0
    for i := 1;i < k; i++{
        dp[i] = min(dp[index3]*3,dp[index5]*5,dp[index7]*7)
        if dp[i] == dp[index3]*3 {
            index3++
        }
        if dp[i] == dp[index5]*5 {
            index5++
        }
        if dp[i] == dp[index7]*7 {
            index7++
        }
    }
    
    return dp[k-1]
}

func min(a, b, c int) int {
    if a <= b && a <= c {
        return a
    }
    
    if b <= a && b <= c {
        return b
    }

    return c
}




```