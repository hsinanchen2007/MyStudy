### 解题思路

不需要观察矩阵规律, 只需要设置一个方向和坐标, 然后遵循右, 下, 左, 上的走发循环走即可. 

执行用时 :
136 ms, 在所有 Swift 提交中击败了84.62%的用户

内存消耗 :
21.5 MB, 在所有 Swift 提交中击败了100.00%的用户

### 代码

```swift
class Solution {

    enum Direction {
        case left
        case right
        case top
        case bottom
    }

    struct Index {
        var row: Int
        var col: Int
        var loop: Int // 圈数
        var direction: Direction // 当前方向
    }

    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        if matrix.count == 0 || matrix[0].count == 0 {
            return [Int]()
        }

        var result = [Int]()

        // 把矩阵看作一个圆
        // 定义一个圈数, 用来标记矩阵已访问的元素从边界开始向圆心扩张的位置
        // 圈数为0, 说明矩阵边界还没有被访问过.
        // 圈数是1, 表示矩阵边界向圆心数, 第1圈元素已经被访问过.
        var index: Index? = Index(row:0, col: 0, loop: 0, direction: .right)
        while index != nil {
            result.append(matrix[index!.row][index!.col])
            
            // 通过 index中的loop和row, col, direction, 就可以计算出下一个index
            if index!.direction == .right {
                if index!.col + 1 < matrix[index!.row].count - index!.loop {
                    index!.col = index!.col + 1
                    continue
                }
            }
            // 无法向右了, 则改向下;
            // 正在向下的, 直接尝试向下
            if index!.direction == .right || index!.direction == .bottom {
                if index!.row + 1 < matrix.count - index!.loop {
                    index!.row = index!.row + 1
                    index!.direction = .bottom
                    continue
                }
            }
            if index!.direction == .bottom || index!.direction == .left {
                if index!.col - 1 >= 0 + index!.loop {
                    index!.col = index!.col - 1
                    index!.direction = .left
                    continue
                }
            }

            if index!.direction == .left || index!.direction == .top {
                // 注意向上的时候, 不需要到第0 + index.loop行, 所以这里是 > 号
                if index!.row - 1 > 0 + index!.loop {
                    index!.row = index!.row - 1
                    index!.direction = .top
                    continue
                }
            }

            let loop = index!.loop + 1
            // 判断能否进入下一圈, 也就是直接向左
            if index!.col + 1 < matrix[index!.row].count - loop && index!.row < matrix.count - loop {
                index!.col = index!.col + 1
                index!.direction = .right
                index!.loop = index!.loop + 1
                continue
            }
            
            index = nil
        }
        
        return result
    }
}

```