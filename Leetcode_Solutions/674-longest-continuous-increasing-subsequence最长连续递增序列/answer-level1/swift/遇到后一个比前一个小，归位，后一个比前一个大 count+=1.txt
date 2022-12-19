```
func findLengthOfLCIS(_ nums: [Int]) -> Int {
    if nums.count == 0 { return 0 }
    var count = 1
    var maxCount = 1
    for i in 0..<nums.count {
        if i+1 >= nums.count { break }
        if nums[i+1] > nums[i] {
            count+=1
        } else {
            count = 1
        }
        maxCount = max(maxCount, count)
    }
    return maxCount
}
```
