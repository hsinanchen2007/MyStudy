### 解题思路
双指针i, j，i重头开始，j从尾开始，如果num[i]是偶数，就交换nums[i], nums[j]直到num[i]是奇数为止

### 代码

```golang
func exchange(nums []int) []int {
    for i, j := 0, len(nums) - 1; i < j; i++ {
        for ; nums[i] % 2 == 0; {
            nums[i], nums[j] = nums[j], nums[i]
            j --
            if(i > j) {
                break
            }
        }
    }
    return nums
}
```