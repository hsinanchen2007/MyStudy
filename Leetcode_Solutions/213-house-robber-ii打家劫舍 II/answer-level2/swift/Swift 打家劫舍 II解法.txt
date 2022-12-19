### 动态规划

由于不可以在相邻的房屋偷窃，所以在当前位置` i `房屋可盗窃的最大值；要么就是`i-1` 房屋可盗窃的最大值，要么就是`i-2` 房屋可盗窃的最大值加上当前房屋的值`nums[i]`，二者之间取最大值
由于第一间和最后一间房子是连在一起的，所以分两种情况
- 最大值包含第一间
- 最大值包含最后一间

### 代码

```swift
class Solution {
    func dp(_ nums:[Int]) -> [Int] {
        var dpArr = Array(repeating: 0, count: nums.count)
        for i in 0..<nums.count {
            let n1 = i > 1 ? dpArr[i - 2] + nums[i] : nums[i]
            let n2 = i > 0 ? dpArr[i - 1] : 0
            dpArr[i] = max(n1, n2)
        }
        return dpArr
    }
    func rob(_ nums: [Int]) -> Int {
        if nums.count == 0 {
            return 0
        }
        if nums.count == 1 {
            return nums.first!
        }
        if nums.count == 2 {
            return max(nums[0], nums[1])
        }
        var arr1: [Int] = nums
        var arr2: [Int] = nums
        arr1.removeFirst()
        arr2.removeLast()
        let dp1 = dp(arr1)
        let dp2 = dp(arr2)
        return max(dp1[nums.count - 2], dp2[nums.count - 2])
    }
}
```