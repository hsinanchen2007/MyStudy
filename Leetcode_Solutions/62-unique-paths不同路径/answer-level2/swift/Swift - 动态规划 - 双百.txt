```
class Solution {
    func uniquePaths(_ m: Int, _ n: Int) -> Int {
        if m <= 0 || n <= 0 {
            return 0
        }
        
        var dp = [[Int]].init(repeating: [Int].init(repeating: 0, count: n), count: m)
        for i in 0..<n { //初始化第一行
            dp[0][i] = 1
        }
        for j in 0..<m { //初始化第一列
            dp[j][0] = 1
        }
        for i in 1..<m {
            for j in 1..<n {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
            }
        }
        return dp[m-1][n-1]
    }
}
```
//提升数据结构和算法，刷题日记，每日积累一点。github仓库包括”跟随极客时间课程例题“、”leetcode高频题目“、”剑指offer的题目“，语言使用Swift和极少部分的Java，欢迎访问一起进步：https://github.com/iAronTalk/Algorithm-DataStructures-Pass