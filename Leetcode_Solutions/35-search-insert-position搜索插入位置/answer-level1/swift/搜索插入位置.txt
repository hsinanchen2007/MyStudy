```
func searchInsert(_ nums: [Int], _ target: Int) -> Int {
    if nums[nums.count - 1] < target {
        return nums.count
    }
    var left = 0
    var right = nums.count - 1
    while left <= right {
        let middle = (left + right) / 2
        if nums[middle] == target {
            return middle
        } else if nums[middle] < target {
            left = middle + 1
        } else {
            right = middle - 1
        }
    }
    return left
}
```
