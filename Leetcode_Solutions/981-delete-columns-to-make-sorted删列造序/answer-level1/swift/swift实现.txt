```
class Solution {
    func minDeletionSize(_ A: [String]) -> Int {
        var D:[Int] = []
        for i in 0..<A[0].count {
            for j in 0..<A.count-1{
                let ca = A[j][String.Index(encodedOffset: i)]
                let cb = A[j+1][String.Index(encodedOffset: i)]
                if ca > cb {
                    D.append(i)
                    break
                }
            }
        }
        return D.count
    }
}
```