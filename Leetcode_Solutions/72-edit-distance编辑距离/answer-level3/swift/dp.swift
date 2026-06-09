```
class Solution {
    func minDistance(_ word1: String, _ word2: String) -> Int {
        if word1 == word2 {
            return 0
        }
        let m = word1.count
        let n = word2.count
        let s1 = Array(word1)
        let s2 = Array(word2)
        var dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
        if m > 0 {
            for i in 1...m { // n = 0
                dp[i][0] = i
            }
        }
        if n > 0 {
            for j in 1...n {
                dp[0][j] = j
            }
        }
        if n == 0 || m == 0 {
            return dp[m][n]
        }
        for i in 1...m {
            for j in 1...n {
                let c1 = s1[i-1]
                let c2 = s2[j-1]
                if c1 == c2 {
                    dp[i][j] = dp[i-1][j-1]
                }else{
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j-1]), dp[i-1][j]) + 1
                }
            }
        }
        return dp[m][n]
    }
}
```