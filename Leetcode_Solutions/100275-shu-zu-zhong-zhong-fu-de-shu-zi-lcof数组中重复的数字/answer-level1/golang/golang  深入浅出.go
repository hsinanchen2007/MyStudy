### 解题思路
1. 题目本身没有什么明显的技法特征, 先考虑排序 然后在遍历得解决
2. 时间复杂度 进一步优化 可以使用哈希表记忆 元素与出现次数的关系
3. 空间复杂度 进一步优化 可以复用原数组作为哈希数组本身 因为题目假设 所有的数都是在[0,n-1] 的 因此原数组的空间足够进行映射
### 代码

```golang
func findRepeatNumber(nums []int) int {
    for i:=0;i<len(nums);i++{
        if i == nums[i]{
            continue
        }else if nums[i] == nums[nums[i]]{
            return nums[i]
        }else{
            nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
        }
    }
    return -1
}
```