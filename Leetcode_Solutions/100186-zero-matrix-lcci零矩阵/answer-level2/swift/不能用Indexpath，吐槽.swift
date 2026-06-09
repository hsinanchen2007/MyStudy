### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func setZeroes(_ matrix: inout [[Int]]) {
        var arr_0 = [CGPoint]()
        // 记录0的位置
        for i in 0..<matrix.count {
            for j in 0..<matrix[i].count {
                if matrix[i][j] == 0 {
                    arr_0.append(CGPoint(x: i, y: j))
                }
            }
        }
        
        // 清除相关行列
        var clearArr = [CGPoint]()// 记录已经清楚的行或者列
        arr_0.forEach { (point) in
            // 行
            if clearArr.contains(where: { (p) -> Bool in
                return p.x == point.x
            }) == false {
                
                matrix[Int(point.x)] = [Int](repeating: 0, count: matrix.first?.count ?? 0)
                clearArr.append(CGPoint(x: point.x, y: -1))
            }
            // 列
            if clearArr.contains(where: { (p) -> Bool in
                return p.y == point.y
            }) == false {
                for i in 0..<matrix.count {
                    matrix[i][Int(point.y)] = 0
                }
                clearArr.append(CGPoint(x: -1, y: point.y))
            }
        }

    }
}
```