```swift
 class Solution {
     func majorityElement(_ nums: [Int]) -> Int {
        return nums.sorted()[nums.count / 2]
     }
 }
```