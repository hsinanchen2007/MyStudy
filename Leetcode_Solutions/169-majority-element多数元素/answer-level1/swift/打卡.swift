### 解题思路
排序解决

### 代码

```swift
class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        let sort = nums.sorted()
        return sort[sort.count/2]
    }
}
```