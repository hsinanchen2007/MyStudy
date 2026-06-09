```
func searchInsert(nums []int, target int) int {
    
    // 遍历所有元素
    for i := 0; i <= len(nums) - 1; i++ {
        // 如果target小于等于当前元素，则返回当前元素的索引
        if target <= nums[i] {
            return i
        }
    }
    
    // 如果上述循环没有找到比target大的元素，则target插入在数组最后
    return len(nums)
}
```
