解题思路：
1.遍历数组，每个数组元素进行逐一对比
2.相同的数组进行剔除
3.注意点：数组元素被删除，数组的长度跟着改变
```
func removeDuplicates(nums []int) int {
    for i, v := range nums {
        for j := i+1; j<len(nums); j++ {
            if v == nums[j] {
                nums = append(nums[:j],nums[j+1:]...)
                j = j - 1
            }
        }
    }
    return len(nums)
}
```
