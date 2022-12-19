class Solution {
       func search(_ nums: [Int], _ target: Int) -> Bool {
            var left = 0
            var right = nums.count - 1
            while left <= right {
                let mid = left + (right - left) / 2
                if nums[mid] == target {
                    return true
                }
                if nums[mid] == nums[left] {
                    left += 1
                } else if nums[mid] > nums[left] {//左侧
                    if target >= nums[left] && target < nums[mid] {
                        right = mid - 1
                    } else {
                        left = mid + 1
                    }
                } else {
                    if target > nums[mid] && target <= nums[right] {//右侧
                        left = mid + 1
                    } else {
                        right = mid - 1
                    }
                }
            }
            
            return false
        }
}