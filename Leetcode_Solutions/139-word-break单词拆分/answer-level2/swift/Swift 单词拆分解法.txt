### 解题思路
**动态规划**
转移成假设`leetcode`可以分解成`leet`和`code`两个字符
`leet`是有解可以被分割的；则我们只需要判断后面的`code`在集合中是否包含，如果包含则有解。


### 代码

```swift
class Solution {
    func wordBreak(_ s: String, _ wordDict: [String]) -> Bool {
        var dp = Array(repeating: false, count: s.count + 1)
        // 表示任意空字符串是可以被分割的
        dp[0] = true
        let wordSet: Set<String> = Set<String>(wordDict)
        // 遍历查看0...n是否有解
        for i in 0..<dp.count {
            for j in 0..<i {
                // 截取j + 1 到 i 的字符判断是否包含在集合中
                let start = s.index(s.startIndex, offsetBy: j)
                let end = s.index(s.startIndex, offsetBy: i)
                let subStr = String(s[start..<end])
                if dp[j] && wordSet.contains(subStr) {
                    dp[i] = true
                    break
                }
            }
        }
        return dp.last!
    }
}
```