![666.jpg](https://pic.leetcode-cn.com/f5061d2f9f05d5ba08e90fdc5dcdb3201cd2595b9b6854f3c00262805c66db7f-666.jpg)

```Go
func removeElement(nums []int, val int) int {
    if len(nums) == 0 {
        return 0
    }
    
    for i := 0; i < len(nums);{
        if nums[i] == val {
            nums = append(nums[:i], nums[i+1:]...)
            continue
        } else {
            i++
        }
    }
    return len(nums)
}
```
