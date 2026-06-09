```
func removeElement(nums []int, val int) int {
    k := 0
    for j :=0;j<len(nums);j++{
        if nums[j] != val{
            nums[k] = nums[j]
            k++
        }
    }
    return k
}
```
