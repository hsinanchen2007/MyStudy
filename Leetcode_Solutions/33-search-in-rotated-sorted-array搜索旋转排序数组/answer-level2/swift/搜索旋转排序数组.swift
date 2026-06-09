```
func search(_ nums: [Int], _ target: Int) -> Int {
    if nums.count <= 0 {
        return -1
    }
    var start = 0
    var end = nums.count - 1
    var mid: Int = 0
    while start <= end {
        mid = start + (end - start) / 2
        if nums[mid] == target {
            return mid
        }
        if nums[start] <= nums[mid] {
            if target >= nums[start] && target < nums[mid] {
                end = mid - 1
            } else {
                start = mid + 1
            }
        } else {
            if target <= nums[end] && target > nums[mid] {
                start = mid + 1
            } else {
                end = mid - 1
            }
        }
    }
    return -1
}
```
