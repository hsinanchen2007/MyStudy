### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func isValid(_ S: String) -> Bool {
        var S = S
        let pattern = #"abc"#
        let regex = try! NSRegularExpression(pattern: pattern)
        while(S.contains("abc")) {
            S = regex.stringByReplacingMatches(in: S, options: [], range: NSRange(S.startIndex..., in: S), withTemplate: "")
        }
        if S != "" {
            return false
        } else {
            return true
        }
    }
}
```