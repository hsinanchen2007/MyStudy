
### 代码

```golang
func bsearch(start int, end int, nums[]int, target int) int{
    if start > end {
        return -1
    }
    mid := (start + end) / 2
    if nums[mid] == target {
        return mid
    } 
    if nums[mid] < target {
        return bsearch(mid + 1, end, nums, target)
    } else {
        return bsearch(start, mid -1 , nums, target)
    }

}
func search(nums []int, target int) int {
    return bsearch(0, len(nums)-1, nums, target)

}
```