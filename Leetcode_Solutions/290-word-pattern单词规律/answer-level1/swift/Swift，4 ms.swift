```swift
class Solution {
    func wordPattern(_ pattern: String, _ str: String) -> Bool {
        let patternChars = [Character](pattern)
        let patternCount = patternChars.count
        let strStrs = str.split(separator: Character(" "))
        let strCount = strStrs.count
        if patternCount != strCount { return false }
        var dict = [Character : String.SubSequence]()
        for index in 0..<patternCount {
            let char = patternChars[index]
            let strStr = strStrs[index]
            if dict.keys.contains(char) {
                if dict[char] != strStr {
                    return false
                }
            } else {
                if dict.values.contains(strStr) {
                    return false
                }
                dict.updateValue(strStr, forKey: char)
            }
        }
        return true
    }
}
```