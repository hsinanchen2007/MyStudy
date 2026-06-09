### 解题思路

### 代码

```swift
class Solution {
    func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
         if nums == nil || nums.count == 0 {
             return 0;
         }
         var j = 0;
         for i in 0..<nums.count {
             if val != nums[i] {
                 nums[j] = nums[i];
                 j += 1;
             }
         }
         return j;
    }
}
```