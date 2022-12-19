```
func majorityElement(nums []int) int {
    if len(nums) ==  0 {
        return -1
    }
    count := 1
    tmp := nums[0]
    for i:=1;i<len(nums);i++{
        if count == 0 {
            tmp = nums[i]
        }
        if nums[i] == tmp {
            count++
        }else{
            count--
        }
    }
    return tmp
}
```
