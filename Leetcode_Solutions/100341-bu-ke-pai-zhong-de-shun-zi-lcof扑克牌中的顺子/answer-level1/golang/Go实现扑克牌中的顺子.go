

```golang
func isStraight(nums []int) bool {
    sort.Ints(nums)
    num := 0
    for i := 0;i<4;i++{
        if nums[i] == 0{
            continue
        }
        if nums[i] == nums[i+1]{
            return false
        }
        num += nums[i+1]-nums[i]
    } 
    return num<5
}
```