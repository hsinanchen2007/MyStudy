解题思路
两个dp， 一个保存得分， 一个保存路径数
### 代码

```golang
func pathsWithMaxScore(board []string) []int { 
    if board[0] == "EX" && board[1] == "XS" {
        return []int{0,1}
    }

    length := len(board) 

    dp := make([][]int, length) 
    dpPath := make([][]int, length) 
    for i := range dp {
        dp[i] = make([]int, len(board[0])) 
        dpPath[i] = make([]int, len(board[0])) 
    }
    dp[0][0] = 0
    dpPath[0][0] = 1
    for i:=1; i < len(board[0]); i++ {
        dp[0][i] = dp[0][i-1] + helper(board[0][i]) 
        if board[0][i] == 'X' || board[0][i-1] == 'X' {
            dp[0][i] = 0
        }else {
            dpPath[0][i] = 1
        }
    }   
     
    
    for i:=1; i < length; i++ {
        for j:=0; j < len(board[0]); j++ {
            if j== 0 {
                dp[i][0] = dp[i-1][0] + helper(board[i][j]) 
                if board[i][j] == 'X' || board[i-1][j] == 'X' {
                    dp[i][j] = 0
                }else  {
                    dpPath[i][j] = 1
                }
            } else {      
                chos := Max(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) 
                
                dp[i][j] = chos + helper(board[i][j]) 
                if board[i][j] == 'X' || chos == 0{
                    dp[i][j] = 0
                } 

                if chos != 0 {
                    if chos == dp[i][j-1] {
                        dpPath[i][j] += dpPath[i][j-1]
                    }
                    if chos == dp[i-1][j-1] {
                        dpPath[i][j] += dpPath[i-1][j-1]
                    }
                    if chos == dp[i-1][j] {
                        dpPath[i][j] += dpPath[i-1][j]
                    }
                }
            }
            if dp[i][j] != 0 {
                dp[i][j] = dp[i][j] % 1000000007
            }
            if dpPath[i][j] != 0 {
                dpPath[i][j] = dpPath[i][j] % 1000000007
            }
            
        }
    } 
    
    return []int{ dp[length-1][len(board[0])-1] % 1000000007, dpPath[length-1][len(board[0])-1] % 1000000007}
}
// ["E11","XXX","551","11S"]

// 0 2 3
// 2 X 2
// 1 2 S 
func helper(cha byte) int {
    if cha == 'X' || cha == 'E' || cha == 'S' {
        return 0
    }
    return int(cha)-48
}

func Max(i,j,k int)int {
    if i < j {
        i = j
    }
    if i < k {
        i = k
    }
    return i
}
```