dp

```swift
class Solution {
    func numberOfArithmeticSlices(_ A: [Int]) -> Int {
        if A.count <= 2 {
            return 0
        }
        var dp: [Int] = Array(repeating: 0, count: A.count)
        var res = 0
        for i in 2..<A.count {
            if A[i] - A[i-1] == A[i-1] - A[i-2] {
                dp[i] = dp[i-1] + 1
                res += dp[i]
            }
        }
        return res
    }
}
```