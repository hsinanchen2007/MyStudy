
### 代码

```swift
class Solution {

    var cache: [String: [String]] = [:]
    var word_set: Set<String> = []
    
    func wordBreak(_ s: String, _ wordDict: [String]) -> [String] {
        if s.count == 0 {
            return []
        }
        word_set = Set<String>(wordDict)
        return word_break(s)
    }
    func word_break(_ s: String) -> [String] {
        if s.count == 0 {
            return [""]
        }
        if let res = cache[s] {
            return res
        }
        var res = [String]()
        for i in 0..<s.count {
            let end = s.index(s.startIndex, offsetBy: i)
            let subStr = String(s[...end])
            if word_set.contains(subStr) {
                let next = s.index(end, offsetBy: 1) 
                let subArr = word_break(String(s[next...]))
                let appendingArr = subArr.map { res -> String in
                    if res == "" {
                        return "\(subStr)"
                    }
                    return "\(subStr) \(res)"
                }
                res += appendingArr 
            }
        }
        cache[s] = res
        return res
    }
}
```