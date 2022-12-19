对 `nums` 从左到右进行处理，每次把一个新的 num 插入到之前结果的所有可以插入的位置。以 `[1, 2, 3]` 的为例：

取得 1：[[1]]
取得 2：[[2, 1], [1, 2]]
取得 3：[[3, 2, 1], [2, 3, 1], [2, 1, 3], [3, 1, 2], [1, 3, 2], [1, 2, 3]]

输出即为结果。
<br>
```swift
class Solution {
    func permute(_ nums: [Int]) -> [[Int]] {
        return next(nums: nums, temp: [[nums[0]]], index: 1)
    }
    
    func next(nums: [Int], temp: [[Int]], index: Int) -> [[Int]] {
        if nums.count <= index { return temp }
        let now = nums[index]
        var ans = [[Int]]()
        for item in temp {
            for index in 0...index {
                var new = item
                new.insert(now, at: index)
                ans.append(new)
            }
        }
        return next(nums: nums, temp: ans, index: index + 1)
    }
}
```