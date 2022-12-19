```
func removeDuplicates(nums []int) int {
    k := 0
    for j:= 1;j<len(nums);j++{
        if nums[j]!=nums[k]{
            nums[k+1] = nums[j]
            k++
        }
    }
    return k+1
}
```
