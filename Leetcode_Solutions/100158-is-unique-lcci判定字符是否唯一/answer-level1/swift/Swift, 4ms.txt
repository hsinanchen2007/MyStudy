```swift
class Solution {
    func isUnique(_ astr: String) -> Bool {
        return Set<Character>(astr).count == astr.count
    }
}
```