执行用时 :
116 ms
, 在所有 Go 提交中击败了
57.50%
的用户
内存消耗 :
8.2 MB
, 在所有 Go 提交中击败了
40.77%
的用户
```go
func removeDuplicates(nums []int) int {
    l := 0
    size := len(nums)
    for r := 1;r < size;r++{
        if nums[l] != nums[r]{
            l++
            nums[l] = nums[r]
        } 
    }
    return l+1
}
```