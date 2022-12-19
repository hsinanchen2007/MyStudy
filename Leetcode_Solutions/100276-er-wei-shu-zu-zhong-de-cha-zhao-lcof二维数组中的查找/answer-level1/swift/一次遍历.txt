``` swift
class Solution {
    func findNumberIn2DArray(_ matrix: [[Int]], _ target: Int) -> Bool {
        let n = matrix.count
        let m = matrix.first?.count ?? 0
        var line = n - 1
        var row = 0
        while line >= 0 && row < m {
            let curNum = matrix[line][row]
            if curNum == target {
                return true
            }
            if curNum > target {
                line = line - 1
            } else {
                row = row + 1
            }
        }
        return false
    }
}
```
从左下角开始遍历，空间复杂度1，时间复杂度o(m + n)