### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func isRectangleOverlap(_ rec1: [Int], _ rec2: [Int]) -> Bool {
        if rec2[0]>=rec1[2] || rec2[2]<=rec1[0] {
            return false
        } 
         if rec2[1]>=rec1[3] || rec2[3]<=rec1[1] {
            return false
        } 
            return true
    }
}
```