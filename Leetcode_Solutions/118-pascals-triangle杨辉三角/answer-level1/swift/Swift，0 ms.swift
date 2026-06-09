```swift
class Solution {
    func generate(_ numRows: Int) -> [[Int]] {
        var ans = [[Int]]()
        for i in 0..<numRows {
            var row = [Int](repeating: 0, count: i + 1)
            row[0] = 1
            row[row.count - 1] = 1
            for index in 0..<row.count {
                if row[index] == 0 {
                    let lastRow = ans[i - 1]
                    row[index] = lastRow[index - 1] + lastRow[index]
                }
            }
            ans.append(row)
        }
        return ans
    }
}
```