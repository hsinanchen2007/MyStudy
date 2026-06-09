
//时间复杂度：O(n)

```swift []
class Solution {
    func reverseWords(_ s: String) -> String {
        return s.split { $0.isWhitespace }.reversed().joined(separator: " ")
    }
}
```
