```
class Solution {
    func countServers(_ grid: [[Int]]) -> Int {
        if grid.count == 0 {
            return 0
        }
        var res = 0
        var rowNum: [Int:Int] = [:]
        var columnNum: [Int:Int] = [:]
        for (row,subs) in grid.enumerated() {
            var curnum = 0
            var susp = 0
            for (column, s) in subs.enumerated() {
                
                if s == 1  {
                    res += 1
                    curnum += 1
                    susp = column
                    columnNum[column] = (columnNum[column] ?? 0) + 1
                }
            }
            if curnum == 1 {
                rowNum[row] = susp
            }
            
        }
        var minus = 0
        for r in rowNum {
            if columnNum.keys.contains(r.value) {
                if columnNum[r.value]! == 1 {
                    minus += 1
                }
            }
        }
        return res - minus
    }
}
```