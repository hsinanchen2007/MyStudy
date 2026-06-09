### 解题思路

动态规划   状态转移   A[i]满足条件   那么dp[i] = dp[i-1]+1， 分两种情况讨论，取两种情况最大值

### 代码

```golang
func maxTurbulenceSize(A []int) int {
    if len(A) == 1 {
        return 1
    }

    return max(fn1(A),fn2(A))
}

// 状态转移   A[i]满足条件   那么dp[i] = dp[i-1]+1
func fn1(A []int) int {
    dp := make([]int, len(A)) 
    
    if A[0]  < A[1] {
         dp[0] = 1 
    }
   
    var result int
    for i:=1; i <len(A)-1; i++ {
        if i %2 == 1 {
            if A[i] > A[i+1] {
                dp[i] = max(dp[i],dp[i-1]+1)
            }
        }else {
            if A[i] < A[i+1] {
                dp[i] = max(dp[i],dp[i-1]+1)
            } 
        }
        result = max(result,dp[i])
    }
    
    return result+1

}

func fn2(A []int) int {
    dp := make([]int, len(A)) 
    
    var result int

    if A[0] >A[1] {
         dp[0] = 1 
    }
   
    for i:=1; i <len(A)-1; i++ {
        if i %2 == 1 {
            if A[i] < A[i+1] {
                dp[i] = max(dp[i],dp[i-1]+1)
            }
        }else {
            if A[i] > A[i+1] {
                dp[i] = max(dp[i],dp[i-1]+1)
            } 
        }
        result = max(result,dp[i])
    }
   
    return result+1
}

func max(i,j int)int {
    if i > j {
        return i
    }
    return j
}

```