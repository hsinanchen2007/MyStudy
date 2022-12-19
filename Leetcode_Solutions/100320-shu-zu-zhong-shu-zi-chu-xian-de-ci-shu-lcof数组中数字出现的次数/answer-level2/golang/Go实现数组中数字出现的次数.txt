

```golang
func singleNumbers(nums []int) []int {
    eor := 0
    for i := 0;i<len(nums);i++{
        eor ^=nums[i]
    }
    rightOne := eor&(^eor+1)
    onlyOne := 0
    for i := 0;i<len(nums);i++{
        if rightOne & nums[i] != 0{
            onlyOne^=nums[i]
        }
    }
    return []int{onlyOne,eor^onlyOne}
}
```