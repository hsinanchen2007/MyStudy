```
class Solution {
    func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
        let left = leftBound(nums, target)
        let right = rightBound(nums, target)
        return [left, right]
    }

    func leftBound(_ nums: [Int], _ target: Int) -> Int {
        var (left, right) = (0, nums.count)
        while left < right {
            let mid = left + (right - left) / 2
            if nums[mid] == target {
                right = mid
            }else if nums[mid] > target {
                right = mid
            }else if nums[mid] < target {
                left = mid + 1
            }
        }

        if left == nums.count || nums[left] != target {
            return -1
        }
        return left
    }

    func rightBound(_ nums: [Int], _ target: Int) -> Int {
        var (left, right) = (0, nums.count)
        while left < right {
            let mid = left + (right - left) / 2
            if nums[mid] == target {
                left = mid + 1
            }else if nums[mid] > target {
                right = mid
            }else if nums[mid] < target {
                left = mid + 1
            }
        }
        print(left)
        if left == 0 || nums[left - 1] != target {
            return -1
        }
        return left - 1
    }
}
```

执行用时 :64 ms, 在所有 swift 提交中击败了100.00%的用户
内存消耗 :21.3 MB, 在所有 swift 提交中击败了5.88%的用户