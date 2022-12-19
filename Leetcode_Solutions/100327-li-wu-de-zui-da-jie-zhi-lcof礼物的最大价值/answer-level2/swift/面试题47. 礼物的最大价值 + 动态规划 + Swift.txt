```
class Solution {
    func maxValue(_ grid: [[Int]]) -> Int {
        if grid.count == 0 {
            return 0
        }
        var dp = [[Int]].init(repeating: [Int].init(repeating: 0, count: grid.first!.count), count: grid.count)
        for m in (0..<grid.count) {
            for n in (0..<grid.first!.count) {
                if m - 1 >= 0 && n - 1 >= 0 {
                    dp[m][n] = max(dp[m-1][n], dp[m][n-1]) + grid[m][n]
                } else if m - 1 < 0 && n - 1 >= 0 {
                    dp[m][n] = dp[m][n-1] + grid[m][n]
                } else if n - 1 < 0 && m - 1 >= 0 {
                    dp[m][n] = dp[m-1][n] + grid[m][n]
                } else {
                    dp[m][n] = grid[m][n]
                }
            }
        }
        return dp[grid.count - 1][grid.first!.count - 1]
    }
}
```

//提升数据结构和算法，刷题日记，每日积累一点。github仓库包括”跟随极客时间课程例题“、”leetcode高频题目“、”剑指offer的题目“，语言使用Swift和极少部分的Java，欢迎访问一起进步：https://github.com/iAronTalk/Algorithm-DataStructures-Pass