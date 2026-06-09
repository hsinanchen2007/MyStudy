```
func search(_ nums: [Int], _ target: Int) -> Bool {
    if nums.count <= 0 {
        return false
    }
    var start = 0
    var end = nums.count - 1
    var mid: Int = 0
    while start <= end {
        mid = start + (end - start)/2
        if nums[mid] == target {
            return true
        }
        if nums[start] == nums[mid] {
            start += 1
            continue
        }
        if nums[start] <= nums[mid] {
            if nums[mid] > target && nums[start] <= target {
                end = mid - 1
            } else {
                start = mid + 1
            }
        } else {
            if nums[mid] < target && nums[end] >= target {
                start = mid + 1
            } else {
                end = mid - 1
            }
        }
    }
    return false
}
```
