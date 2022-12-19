```
func moveZeroes(nums []int)  {
    j := 0
    for i := 0; i < len(nums); i++ {
        if nums[i] != 0 {
            nums[j] = nums[i]
            if i != j {
                nums[i] = 0
            }
            j++
        }
    }
}
```
时间复杂度
O(n)
空间复杂度
O(1)