
### 代码

```swift
class Solution {
    func wordBreak(_ s: String, _ wordDict: [String]) -> Bool {
        let count = s.count
        var mem: [Bool] = Array(repeating: false, count: count + 1)
        mem[0] = true
        for i in 1...count {
            for j in 0..<i {
                let st = s.index(s.startIndex, offsetBy: j)
                let ed = s.index(s.startIndex, offsetBy: i-1)
                print("\(wordDict.contains(String(s[st...ed])))")
                if mem[j] && wordDict.contains(String(s[st...ed])) {
                    mem[i] = true
                    break
                }
            }
        }
        return mem[count]
    }
}
```