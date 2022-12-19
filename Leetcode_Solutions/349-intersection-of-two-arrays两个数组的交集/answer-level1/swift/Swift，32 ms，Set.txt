```swift
class Solution {
    func intersection(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        return Array(Set<Int>(nums1).intersection(Set<Int>(nums2)))
    }
}
```