时间复杂度: O(M*N)

```swift
class Solution {
    func findNumberIn2DArray(_ matrix: [[Int]], _ target: Int) -> Bool {
        for (_, mValue) in matrix.enumerated()  {
            for (_, nValue) in mValue.enumerated() {
                if target == nValue {
                    return true
                }
            }
        }
        return false
    }
}
```