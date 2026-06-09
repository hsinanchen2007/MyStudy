### 解题思路
- 降维，降重叠区域转换成不重叠区域，再取反就是结果
### 代码

```swift
class Solution {
    func isRectangleOverlap(_ rec1: [Int], _ rec2: [Int]) -> Bool {

        let x_overlap = rec2[0] >= rec1[2] || rec1[0] >= rec2[2]
        let y_overlap = rec2[1] >= rec1[3] || rec1[1] >= rec2[3]
        return !x_overlap && !y_overlap
    }
}
```