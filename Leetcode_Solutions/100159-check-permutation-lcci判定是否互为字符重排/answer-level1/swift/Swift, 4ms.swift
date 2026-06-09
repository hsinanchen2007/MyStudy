```swift
class Solution {
    func CheckPermutation(_ s1: String, _ s2: String) -> Bool {
        let s1Chars = Set<Character>(s1)
        let s2Chars = Set<Character>(s2)
        return s1Chars.isSubset(of: s2Chars) && s2Chars.isSubset(of: s1Chars)
    }
}
```