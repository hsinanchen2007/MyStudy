### 解题思路
类似于回文拆分 

### 代码

```swift
class Solution {
    func wordBreak(_ s: String, _ wordDict: [String]) -> Bool {
        if s.count == 0 {
            return true
        }
        if wordDict.count == 0 {
            return s.count == 0
        }
        var dp = Array(repeating: false, count: s.count + 1)
        dp[0] = true
        var maxLen = 0;
        for word in wordDict {
            maxLen = max(maxLen, word.count)
        }
        for i in 1..<s.count + 1 {
            for j in max(0, i - maxLen)..<i {
                if dp[j] && wordDict.contains((s as NSString).substring(with: NSMakeRange(j, i - j))) {
                    dp[i] = true
                    break
                }
            }
        }
        return dp[s.count]
    }
}
```