```
class Solution {
    func transpose(_ A: [[Int]]) -> [[Int]] {
        var result = [[Int]](repeating: [Int](repeating: 0, count: A.count), count: A[0].count)
        for i in 0..<A.count {
            for j in 0..<A[0].count{
                result[j][i] = A[i][j]
            }
        }
        return result
    }
}
```