```swift
class Solution {
    func isPalindrome(_ s: String) -> Bool {
        let chars = "a"..."z", nums = "0"..."9"
        let sCharsFiltered = [Character](s.lowercased().filter({ chars.contains(String($0)) || nums.contains(String($0)) }))
        if sCharsFiltered.isEmpty { return true }
        let count = sCharsFiltered.count
        for index in 0..<(count / 2) {
            if sCharsFiltered[index] != sCharsFiltered[count - index - 1] {
                return false
            }
        }
        return true
    }
}
```