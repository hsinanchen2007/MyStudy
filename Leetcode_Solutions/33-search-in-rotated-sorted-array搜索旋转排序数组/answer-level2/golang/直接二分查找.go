二分法查找
```go
func search(nums []int, target int) int {
    n := len(nums)
    l, r := 0, n
    var m int
    for l < r {
        m = l + (r-l) >> 1
        if nums[m] == target {
            return m
        } else if nums[l] == target {
            return l
        } else if nums[r-1] == target {
            return r-1
        }
        if nums[l] < nums[m] {
            if target > nums[m] || nums[l] > target {
                l = m+1
            } else {
                r = m
            }
        } else {
            if nums[m] > target || target > nums[r-1] {
                r = m
            } else {
                l = m+1
            }
        }
    }
    return -1
}
```

- 执行用时 : 4 ms, 在Search in Rotated Sorted Array的Go提交中击败了96.00% 的用户
- 内存消耗 : 2.6 MB, 在Search in Rotated Sorted Array的Go提交中击败了49.65% 的用户