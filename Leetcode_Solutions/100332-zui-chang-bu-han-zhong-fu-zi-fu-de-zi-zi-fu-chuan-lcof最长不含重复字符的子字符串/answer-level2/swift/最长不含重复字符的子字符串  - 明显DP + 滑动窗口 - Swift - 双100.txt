//动态规划
```
class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        if s.count == 0 {
            return 0
        }
        let sArray = Array(s)
        var dp = [Int].init(repeating: 0, count: sArray.count) //记录当前位置的不重复的长度是多少。
        dp[0] = 1
        var maxLen = 1
        var map = [Character: Int]() //key为字符，value为其出现的最近一次下标。
        map[sArray.first!] = 0
        for index in 1..<sArray.count {
            let char = sArray[index]
            if !map.keys.contains(char) || (index - map[char]!) > dp[index - 1] {
                dp[index] = dp[index - 1] + 1
            } else {
                dp[index] = index - map[char]!
            }
            map[char] = index
            maxLen = max(maxLen, dp[index])
        }
        return maxLen
    }
}
```
//滑动窗口
```
class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        if s.count == 0 {
            return 0
        }
        let sArray: [Character] = Array(s)
        var low = 0
        var res = 0
        for high in 0..<sArray.count {
            if low < high && sArray[low..<high].contains(sArray[high]) {
                while low < high && sArray[low..<high].contains(sArray[high]) {
                    low += 1
                }
            } else {
                res = max(res, high - low + 1)
            }
        }
        return res
    }
}
```




//提升数据结构和算法，刷题日记，每日积累一点。github仓库包括”跟随极客时间课程例题“、”leetcode高频题目“、”剑指offer的题目“，语言使用Swift和极少部分的Java，欢迎访问一起进步：https://github.com/iAronTalk/Algorithm-DataStructures-Pass