

class Solution {
    func findPeakElement(_ nums: [Int]) -> Int {
        return searchNum(nums, left: 0, right: nums.count - 1)
    }

    func searchNum(_ nums: [Int], left: Int, right: Int) -> Int {
        if left == right {
            return left
        }
        
        let mid = left + (right - left) / 2
        if nums[mid] > nums[mid + 1] {
            return searchNum(nums, left: left, right: mid)
        }
        return searchNum(nums, left: mid + 1, right: right)
    }
}