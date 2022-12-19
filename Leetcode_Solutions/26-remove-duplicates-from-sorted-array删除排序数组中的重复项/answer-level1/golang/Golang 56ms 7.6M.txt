```
func removeDuplicates(nums []int) int {
    nlen := len(nums)-1
    index := 1
    for i:=0; i<nlen; i++{
        if nums[i]!=nums[i+1]{
            nums[index] = nums[i+1]
            index++
        }
    }
    return index
}
```
