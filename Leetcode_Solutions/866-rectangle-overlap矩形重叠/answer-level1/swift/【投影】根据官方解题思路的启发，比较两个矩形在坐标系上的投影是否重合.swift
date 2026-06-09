### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {

    func isRectangleOverlap(_ rec1: [Int], _ rec2: [Int]) -> Bool {
    var x_t = true
    if rec2[0] >= rec1[0]{//
        if rec2[0] >= rec1[2] {
            x_t = false
        }
    }else{
        if rec1[0] >= rec2[2] {
            x_t = false
        }
    }
    var y_t = true
    if rec2[1] >= rec1[1]{//
        if rec2[1] >= rec1[3] {
            y_t = false
        }
    }else{
        if rec1[1] >= rec2[3] {
            y_t = false
        }
    }

    return x_t && y_t
}

}
```