class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        /// 输入数组为空，返回空数组
        guard numbers.count > 0 else { return [] }
        let len = numbers.count
        for left in 0..<numbers.count - 1 {
            let right = binarySearch(nums: numbers, left: left + 1, right: len - 1, target: target - numbers[left])
            if right != -1 {
                return [left + 1, right + 1]
            }
        }
        return []
    }
    
    /// 二分查找
    func binarySearch(nums: [Int], left: Int, right: Int, target: Int) -> Int {
        var theLeft = left
        var theRight = right
        while theLeft < theRight {
            let mid = (theLeft + theRight) >> 1
            if nums[mid] < target {
                theLeft = mid + 1
            } else {
                theRight = mid
            }
        }
        if nums[theLeft] == target {
            return theLeft
        }
        return -1
    }
}