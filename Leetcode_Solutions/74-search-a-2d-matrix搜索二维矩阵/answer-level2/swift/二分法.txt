```
class Solution {
    func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
        let m = matrix.count
        if m == 0 {
            return false
        }
        let n = matrix[0].count
        if n == 0 {
            return false
        }
        var begin = 0
        var end = m*n-1
        var middle = (begin+end)>>1
        var row = 0
        var column = 0
        helper74(middle, m, n, &row, &column)
        var value = matrix[row][column]
        var flag = value != target
        if !flag {
            return true
        }
        while flag {
            if value > target {
                end = middle
            } else {
                if begin == middle {
                    begin = end
                } else {
                    begin = middle
                }
            }
            middle = (begin+end)>>1
            helper74(middle, m, n, &row, &column)
            value = matrix[row][column]
            flag = value != target
            if !flag {
                return true
            }
            if begin == end {
                break
            }
        }
        return false
    }
    func helper74(_ value:Int, _ m:Int, _ n:Int, _ row:inout Int, _ column:inout Int) {
        row = value/n
        column = (value+1)%n == 0 ? n-1 : (value+1)%n-1
    }
}
```
