```swift
class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        return (nums + [target]).sorted().firstIndex(of: target)!
    }
}
```