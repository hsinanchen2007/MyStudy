
使用类似快排的思想


```swift []
class Solution {
    func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
        return findKth(nums, k, low: 0, high: nums.count - 1)
    }
    
    func findKth(_ nums: [Int], _ k: Int, low: Int, high: Int) -> Int {
        var copy = [Int].init(nums)
        let mid = partion(&copy, low: low, high: high)
        if mid == k - 1 {
            return copy[mid]
        } else if mid < k - 1 {
            return findKth(copy, k, low: mid + 1, high: high)
        } else {
            return findKth(copy, k, low: low, high: mid - 1)
        }
    }
    
    func partion(_ nums: inout [Int], low: Int, high: Int) -> Int {
        guard low <= high, high < nums.count else {
            return -1
        }
        var tmp = nums[low]
        var startIdx = low
        var endIdx = high
        while startIdx < endIdx {
            while startIdx < endIdx, nums[endIdx] <= tmp {
                endIdx = endIdx - 1
            }
            nums[startIdx] = nums[endIdx]
            
            while startIdx < endIdx, nums[startIdx] >= tmp {
                startIdx = startIdx + 1
            }
            nums[endIdx] = nums[startIdx]
        }
        nums[startIdx] = tmp
        return startIdx
    }
}
```
