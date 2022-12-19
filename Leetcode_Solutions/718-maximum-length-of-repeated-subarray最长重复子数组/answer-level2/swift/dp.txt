```
func findLength(_ A: [Int], _ B: [Int]) -> Int {
    var dp = [[Int]](repeating: [Int](repeating: 0, count: B.count + 1), count: A.count + 1)
    var i = 0
    var res = 0 
    while i < A.count {
        var j = 0
        while j < B.count {
            if A[i] == B[j] {
                 dp[i + 1][j + 1] = dp[i][j] + 1
                res = max(res, dp[i + 1][j + 1])
            }else{
                dp[i + 1][j + 1] = 0
            }
            j += 1
        }
        i += 1
    }
    return res
}
```