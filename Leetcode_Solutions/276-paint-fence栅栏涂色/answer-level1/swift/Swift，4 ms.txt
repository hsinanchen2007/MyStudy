```swift
class Solution {
    func numWays(_ n: Int, _ k: Int) -> Int {
        if n == 0 || k == 0 { return 0 }
        if n == 1 { return k }
        var dp: [Int] = [Int](repeating: 0, count: n)
        dp[0] = k
        dp[1] = k * k
        if n > 1 {
            for i in 2..<n {
                dp[i] = dp[i - 2] * (k - 1) + dp[i - 1] * (k - 1)
            }
        }
        return dp[n - 1]
    }
}
```