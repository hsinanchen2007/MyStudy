### 解题思路
逐个遍历数组中的元素，和前面的元素比较，插入合适的位置。

### 代码

```golang
func sortArray(nums []int) []int {
    
    for i := 0; i < len(nums); i++ {
        for j := i; j > 0; j-- {
            if nums[j] < nums[j-1] {
                nums[j], nums[j-1] = nums[j-1], nums[j]
            }
        }
    }
    return nums
}
```