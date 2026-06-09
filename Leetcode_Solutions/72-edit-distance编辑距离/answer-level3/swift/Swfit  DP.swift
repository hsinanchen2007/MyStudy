```
class Solution {
    func minDistance(_ word1: String, _ word2: String) -> Int {
        let m = word1.count
        let n = word2.count
        if m == 0 {
            return n
        }
        if n == 0 {
            return m
        }
        var dp = [[Int]].init(repeating: [Int].init(repeating: 0, count: n + 1), count: m + 1)
        //i表示单词1对比到哪一位，j表示单词2对比到哪一位，存储的数值代码对比到i和j的位置，走了多少步骤。
        for i in 0...m {
            dp[i][0] = i
        }
        for j in 0...n {
            dp[0][j] = j
        }

        for i in 1...m {
            for j in 1...n {
                let startI = word1.startIndex
                let startJ = word2.startIndex
                let indexI = word1.index(startI, offsetBy: i - 1)
                let indexj = word2.index(startJ, offsetBy: j - 1)
                dp[i][j] = min(dp[i-1][j-1] + (word1[indexI] == word2[indexj] ? 0 : 1), dp[i-1][j] + 1, dp[i][j-1] + 1)
            }
        }
        return dp[m][n]
    }
}
```