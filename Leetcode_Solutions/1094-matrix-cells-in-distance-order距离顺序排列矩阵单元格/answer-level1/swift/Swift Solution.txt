原理是从中心向四周扩散。
假设中心到矩阵边缘最远的距离为radius (就是(r0, c0)与四个边角的距离中最大的那个)
扩散半径从1~radius逐步增加，对于某个给定的radius, 在这个半径范围内任意符合条件的(ri, cj)应该满足

|r0 - ri| + |c0 - cj| = radius

```
func allCellsDistOrder(_ R: Int, _ C: Int, _ r0: Int, _ c0: Int) -> [[Int]] {
    var radius = max(abs(r0) + abs(c0), abs(r0) + abs(c0 - (C - 1)))
    radius = max(radius, abs(r0 - (R - 1)) + abs(c0))
    radius = max(radius, abs(r0 - (R - 1)) + abs(c0 - (C-1)))
    
    var res = [[Int]]()
    
    res.append([r0, c0])
    
    func append(_ res : inout [[Int]], i : Int, j : Int) {
        //check boundary
        if (i >= 0 && i < R) && (j >= 0 && j < C) {
            res.append([i, j])
        }
    }
    
    for distance in 1...radius {
        for rowDistance in 0...distance {
            if rowDistance == 0 {
                append(&res, i: r0 - rowDistance, j: c0 - (distance - rowDistance))
                append(&res, i: r0 - rowDistance, j: c0 + (distance - rowDistance))
            } else if rowDistance == distance {
                append(&res, i: r0 - rowDistance, j: c0 - (distance - rowDistance))
                append(&res, i: r0 + rowDistance, j: c0 - (distance - rowDistance))
            } else {
                append(&res, i: r0 - rowDistance, j: c0 - (distance - rowDistance))
                append(&res, i: r0 - rowDistance, j: c0 + (distance - rowDistance))
                append(&res, i: r0 + rowDistance, j: c0 - (distance - rowDistance))
                append(&res, i: r0 + rowDistance, j: c0 + (distance - rowDistance))
            }
        }
    }
    
    return res
}
```
