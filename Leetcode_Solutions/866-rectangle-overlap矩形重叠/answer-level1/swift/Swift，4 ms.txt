```swift
class Solution {
    func isRectangleOverlap(_ rec1: [Int], _ rec2: [Int]) -> Bool {
        /*let center1 = (x: (rec1[0] + rec1[2]) / 2, y: (rec1[1] + rec1[3]) / 2)
        let width1Half = abs(rec1[0] - rec1[2]) / 2
        let height1Half = abs(rec1[1] - rec1[3]) / 2
        let center2 = (x: (rec2[0] + rec2[2]) / 2, y: (rec2[1] + rec2[3]) / 2)
        let width2Half = abs(rec2[0] - rec2[2]) / 2
        let height2Half = abs(rec2[1] - rec2[3]) / 2
        return abs(center1.x - center2.x) < (width1Half + width2Half) && abs(center1.y - center2.y) < (height1Half + height2Half)*/
        return abs((rec1[0] + rec1[2]) - (rec2[0] + rec2[2])) < (abs(rec1[0] - rec1[2]) + abs(rec2[0] - rec2[2])) && abs((rec1[1] + rec1[3]) - (rec2[1] + rec2[3])) < (abs(rec1[1] - rec1[3]) + abs(rec2[1] - rec2[3]))
    }
}
```