```
class Solution {
    func nthUglyNumber(_ n: Int) -> Int {
        if n == 0 {
            return 0
        }
        var dp = [Int].init(repeating: 1, count: n)
        var a = 0, b = 0, c = 0 //a、b、c表示前面可以通过乘以2、3、5得到下一个的丑数的【坐标】，依次增长，可以保证前面所有通过乘以2或者3或者5的数都可以遍历到。
        for index in 1..<n {
            let n1 = dp[a] * 2, n2 = dp[b] * 3, n3 = dp[c] * 5
            dp[index] = min(n1, n2, n3)
            if dp[index] == n1 {
                a += 1
            }
            if dp[index] == n2 {
                b += 1
            }
            if dp[index] == n3 {
                c += 1
            }
        }
        return dp[ n - 1]
    }
}
```

//提升数据结构和算法，刷题日记，每日积累一点。github仓库包括”跟随极客时间课程例题“、”leetcode高频题目“、”剑指offer的题目“，语言使用Swift和极少部分的Java，欢迎访问一起进步：https://github.com/iAronTalk/Algorithm-DataStructures-Pass