```swift
class Solution {
    func reverse(_ x: Int) -> Int {
        guard x != 0 else { return 0 }
        let isNegativeNumber = x < 0
        let newValue = isNegativeNumber ? -x : x
        var reversedStr = String("\(newValue)".reversed())
        while reversedStr.hasPrefix("0") {
            reversedStr.removeFirst()
        }
        let result = NSString(string: reversedStr).integerValue
        guard result < Int32.max else { return 0 }
        return isNegativeNumber ? -result : result
    }
}
```
