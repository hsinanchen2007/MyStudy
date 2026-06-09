### 解题思路
dp[k][i][j], k表示步数，  i,j 表示坐标 

### 代码

```golang
func findPaths(m int, n int, N int, i int, j int) int {
    var result int
    
    dp := make([][][]int, N+1)
    for i := range dp {
        dp[i] = make([][]int, m+2) 
        for j := range dp[i] {
            dp[i][j] = make([]int, n+2)
        }
    }
   
    dp[0][i+1][j+1] = 1
    for k:=1; k <= N; k++ { 
        for i:=0; i <= m+1 ; i++ {
            for j:=0; j <= n+1; j++ {  
                if ok(m,n,i,j) == false {
                    dp[k][i][j] = dp[k-1][i][j]
                }
                if ok(m,n,i-1,j) {
                    dp[k][i][j] += dp[k-1][i-1][j]
                }
                if ok(m,n,i+1,j) {
                    dp[k][i][j] += dp[k-1][i+1][j]
                }
                if ok(m,n,i,j-1) {
                    dp[k][i][j] += dp[k-1][i][j-1]
                }
                if ok(m,n,i,j+1) {
                    dp[k][i][j] += dp[k-1][i][j+1]
                }
                dp[k][i][j] %= 1000000007
                // sum 
                if k == N && !ok(m,n,i,j) {
                    result += dp[k][i][j]     
                    result = result % 1000000007  
                }
            }
        }
       
    } 
   
    return result
} 
// dp[k][i][j], k表示步数，  i,j 表示坐标 

// dp[k][i][j] = dp[k-1][][], {(i-1,j),(i+1,j),(i, j+1), (i,j-1)} sum
func ok(m,n, i,j int) bool { // 在方格內
    if i>=1 && i <= m && j >=1 && j <= n {
        return true
    }
    return false
}


// 回溯 超时
// func helper(m int, n int, N int, i int, j int, result *int) {
//     if ok(m,n,i,j) && N >= 0{
//         *result++ 
//         *result = *result % 1000000007
//         return 
//     }
//     if N == 0 {
//         return 
//     }

//     helper(m , n , N-1 , i-1 , j , result) 
//     helper(m , n , N-1 , i+1 , j , result) 
//     helper(m , n , N-1 , i , j-1 , result) 
//     helper(m , n , N-1 , i , j+1 , result) 
// }


```