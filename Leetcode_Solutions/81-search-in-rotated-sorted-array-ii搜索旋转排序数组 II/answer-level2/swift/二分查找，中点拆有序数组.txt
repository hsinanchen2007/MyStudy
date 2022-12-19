
class Solution {
    func search(_ nums: [Int], _ target: Int) -> Bool {
    
        guard !nums.isEmpty else {
            return false
        }
    
        guard nums.count > 1 else {
            return nums.first! == target
        }
        
        var sortedOne: [Int] = [], sortedTwo: [Int] = []
        var low = 0, high = nums.count - 1
        var pre = low + 1
    
        while low < high {
            if nums[low] > nums[pre] {
                sortedOne = Array(nums[0...low])
                sortedTwo = Array(nums[pre...high])
                break
            } else {
                low += 1
                pre = low + 1
            }
        }
        
        if low == high {
            sortedOne = nums
        }
    
        return binarySearch(nums: sortedOne, target: target) || binarySearch(nums: sortedTwo, target: target)
    }

    func binarySearch(nums: [Int], target: Int) -> Bool {
    
        guard !nums.isEmpty else {
            return false
        }
    
        guard nums.count > 1 else {
            return nums.first! == target
        }
    
        var low = 0, high = nums.count - 1
    
        while low < high {
            let mid = low + (high - low)/2
            if nums[mid] > target {
                high = mid
            } else if nums[mid] < target {
                low = mid + 1
            } else {
                return true
            }
        }
    
        return nums[low] == target
    }
}