```swift
class Solution {
    func firstUniqChar(_ s: String) -> Int {
        var set = Set<Character>()
        var index = 0
        for char in s {
            if !set.contains(char) {
                set.insert(char)
                if s.lastIndex(of: char)! == s.index(s.startIndex, offsetBy: index) {
                    return index
                }
            }
            index += 1
        }
        return -1
    }
}
```