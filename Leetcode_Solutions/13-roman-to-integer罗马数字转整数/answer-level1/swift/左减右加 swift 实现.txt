```swift
class Solution {
    func romanToInt(_ s: String) -> Int {
        let maps = ["I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000]
        var result = 0
        let str = s as NSString
        for i in 0..<s.count {
            let value1 = maps[str.substring(with: NSRange(location: i, length: 1))]!
            let value2: Int
            if i+1 == s.count {
                value2 = 0
            } else {
               value2 = maps[str.substring(with: NSRange(location: i+1, length: 1))]!
            }
            
            if value1 < value2 {
                result -= value1
            } else {
                result += value1
            }
        }
        return result
    }
}
```
