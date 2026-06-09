```
func removeDuplicates(_ nums: inout [Int]) -> Int {
        let set:Set = Set(nums)
        nums = Array(set)
        nums.sort()
        return nums.count
    }
```