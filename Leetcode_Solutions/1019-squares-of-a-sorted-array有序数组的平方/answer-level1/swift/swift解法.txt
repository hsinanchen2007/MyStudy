```
class Solution {
    func sortedSquares(_ A: [Int]) -> [Int] {
        var a = A
        for i in 0..<A.count{
            a[i]*=a[i]
        }
        a.sort()
        return a
    }
}
```