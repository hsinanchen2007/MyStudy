### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
 func majorityElement(_ nums: [Int]) -> Int {
    return  nums.reduce(into: [:]) { counts, number in
           counts[number, default: 0] += 1
           }.filter{$0.value > nums.count>>1}.keys.first!
 }
}
```