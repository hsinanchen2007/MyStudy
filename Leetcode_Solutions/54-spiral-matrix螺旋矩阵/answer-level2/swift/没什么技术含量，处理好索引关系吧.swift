

### 代码

```swift
class Solution {
func spiralOrder(_ matrix: [[Int]]) -> [Int] {
    var minY = 1
    var maxY = matrix.count - 1
    guard maxY >= 0 else { return [] }
    
    var minX = 0
    var maxX = (matrix.first?.count)! - 1
    guard maxX >= 0 else { return [] }
    
    var result = [Int]()
    var x = 0
    var y = 0
    
    var k = 0
    
    loop: while true {
        result.append(matrix[y][x])
        
        switch k {
        case 0:
            if x < maxX {
                x += 1
            } else {
                if y < maxY {
                    k = 1
                    maxX -= 1
                    y += 1
                } else {
                    break loop
                }
            }
        case 1:
            if y < maxY {
                y += 1
            } else {
                if x > minX {
                    maxY -= 1
                    k = 2
                    x -= 1
                } else {
                    break loop
                }
            }
        case 2:
            if x > minX {
                x -= 1
            } else {
                if y > minY {
                    minX += 1
                    k = 3
                    y -= 1
                } else {
                    break loop
                }
            }
        case 3:
            if y > minY {
                 y -= 1
             } else {
                if x < maxX {
                    minY += 1
                     k = 0
                     x += 1
                } else {
                    break loop
                }
             }
        default:
            break
        }
    }
    
    return result
}

}
```