### 解题思路
- DP

### 代码

```swift
class Solution {
    func massage(_ nums: [Int]) -> Int {

        if nums.isEmpty {
            return 0
        }
        let num = nums.count
        if num == 1 {
            return nums[0]
        }
        var dp = [Int](repeating: 0, count: num)
        for i in 0..<num {
            let n1 = i > 0 ? dp[i - 1]:0
            let n2 = i > 1 ? dp[i - 2] + nums[i] : nums[i]
            dp[i] = max(n1, n2)
        }
        return dp[num - 1]
    }
}
```