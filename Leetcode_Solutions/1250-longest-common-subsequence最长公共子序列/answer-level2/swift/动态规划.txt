```
class Solution {
    func longestCommonSubsequence(_ text1: String, _ text2: String) -> Int {
        let n1 = text1.count
        let n2 = text2.count
        let t1 = Array(text1)
        let t2 = Array(text2)
        var dp = Array(repeating: Array(repeating: 0, count: n2 + 1), count: n1 + 1)
        for i in 1...n1 {
            for j in 1...n2 {
                let c1 = t1[i-1]
                let c2 = t2[j-1]
                if c1 == c2 {
                    dp[i][j] = dp[i-1][j-1] + 1
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                }
            }
        }
        return dp[n1][n2]
    }
}
```