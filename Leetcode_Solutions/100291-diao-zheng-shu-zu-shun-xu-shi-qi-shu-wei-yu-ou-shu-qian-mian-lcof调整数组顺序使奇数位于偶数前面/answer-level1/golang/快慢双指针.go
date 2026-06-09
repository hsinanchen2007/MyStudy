### 解题思路
快慢爽指针。
- 快指针`i`，进行遍历处理;
- 慢指针`j`，始终指向当前数组中的第一个偶数。
- 当快指针指向奇数时候，交换`nums[i]`和`nums[j]`并将`i`和`j`进行自增；
- 当快指针指向偶数时候，仅将`i`进行自增操作。
### 代码

```golang
func exchange(nums []int) []int {
    j := 0
    for i := 0 ; i < len(nums); i++{
        if nums[i]%2 == 1{
            nums[i], nums[j] = nums[j], nums[i]
            j++
        }
    }
    return nums
}
```