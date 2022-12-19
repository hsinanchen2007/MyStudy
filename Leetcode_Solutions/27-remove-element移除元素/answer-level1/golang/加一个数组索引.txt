```
func removeElement(nums []int, val int) int {
    
    // 索引指向当前有效的数组位置
    pos := 0
    
    // 遍历数组
    for i := 0; i <= len(nums) - 1; i++ {
        
        if nums[i] == val {  // 如果相同，则直接跳过
            continue
        } else {  // 如果不同，则更新当前位置的元素，并把有效索引移动到下一个位置
            nums[pos] = nums[i]
            pos++
        } 
        
    }
    
    return pos
}
```
