
### 代码

```swift
class Solution {
    func findTargetSumWays(_ nums: [Int], _ S: Int) -> Int {
        var sum = 0
        for item in nums {
            sum += item
        }
        if sum < S {
            return 0
        }
        var res = 0
        dfs_findTarget(nums, S, 0, &res)
        return res
    }

    func dfs_findTarget(_ nums: [Int], _ S: Int, _ i: Int, _ res: inout Int) {
        if i == nums.count {
            if S == 0 {
                res += 1
            }
            return
        }
         // 上一个元素选的是 + 号, 所以 S 减少了
        dfs_findTarget(nums, S - nums[i], i + 1, &res)
        // 上一个元素选的是 - 号, 所以 S 增加了
        dfs_findTarget(nums, S + nums[i], i + 1, &res)
    }
}
```