### 解题思路
**解法一： 动态规划**
由于不可以在相邻的房屋偷窃，所以在当前位置 `i` 房屋可盗窃的最大值；要么就是`i-1` 房屋可盗窃的最大值，要么就是`i-2` 房屋可盗窃的最大值加上当前房屋的值`nums[i]`，二者之间取最大值
**解法二： 见注释**

### 代码

```swift
class Solution {
    func rob(_ nums: [Int]) -> Int {
        if nums.count == 0 {
            return 0
        }
        if nums.count == 1 {
            return nums[0]
        }
        var dp = Array(repeating: 0, count: nums.count)
        for i in 0..<nums.count {
            let n1 = i > 1 ? dp[i - 2] + nums[i] : nums[i]
            let n2 = i > 0 ? dp[i - 1] : 0
            dp[i] = max(n1, n2)
        }
        return dp[nums.count - 1]
// 解法二：
        // var num1 = 0
        // var num2 = 0
        // for(i, item) in nums.enumerated() {
        //     if i % 2 == 0 {
        //         num1 += item
        //         num1 = max(num1, num2)
        //     } else {
        //         num2 += item
        //         num2 = max(num2, num1)
        //     }
        // }
        // return max(num1, num2)
    }
}
```