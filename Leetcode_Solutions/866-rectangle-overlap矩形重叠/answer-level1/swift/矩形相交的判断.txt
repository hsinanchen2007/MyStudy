### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func isRectangleOverlap(_ rec1: [Int], _ rec2: [Int]) -> Bool {
       let rect1X1 = rec1[0]
            let rect1Y1 = rec1[1]
            let rect1X2 = rec1[2]
            let rect1Y2 = rec1[3]
            
            let rect2X1 = rec2[0]
            let rect2Y1 = rec2[1]
            let rect2X2 = rec2[2]
            let rect2Y2 = rec2[3]
                
            let overlapX1 = max(rect1X1, rect2X1)
            let overlapY1 = max(rect1Y1, rect2Y1)
            
            let overlapX2 = min(rect1X2, rect2X2)
            let overlapY2 = min(rect1Y2, rect2Y2)
                
        if overlapX1 >= overlapX2 || overlapY1 >= overlapY2 {
            return false
        }
        
        
        
        return true
    }
}
```