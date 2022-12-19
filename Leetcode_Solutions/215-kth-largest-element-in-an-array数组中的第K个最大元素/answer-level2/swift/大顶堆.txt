### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
    if nums.count == 0 { return 0 }
    var nums = nums
    // 批量建堆
    var index = max(0, nums.count >> 1 - 1)
    while index >= 0 {
        //print("index:\(index)")
        shiftDown(&nums, index: index)
        index -= 1
    }
    var ans = 0
    for _ in 0..<k {
        ans = nums[0]
        //print("ans:\(ans)")
        let last = nums.removeLast()
        if nums.count > 0 {
            nums[0] = last
        }
        shiftDown(&nums, index: 0)
    }
    return ans
}

/// 下滤
func shiftDown(_ nums: inout [Int], index: Int) {
    var index = index
    while true {
        var maxChildIndex = index << 1 + 1 // 左
        if maxChildIndex >= nums.count {
            // 是叶子节点
            return
        }
        let rightChildIndex = maxChildIndex + 1
        if rightChildIndex < nums.count && nums[rightChildIndex] > nums[maxChildIndex] {
            maxChildIndex = rightChildIndex
        }
        if nums[index] >= nums[maxChildIndex] {
            return
        }
        //print("maxIndex:\(maxChildIndex), val:\(nums[maxChildIndex])")
        // 交换
        let temp = nums[index]
        nums[index] = nums[maxChildIndex]
        nums[maxChildIndex] = temp
        index = maxChildIndex
        //print(nums)
    }
}
}
```