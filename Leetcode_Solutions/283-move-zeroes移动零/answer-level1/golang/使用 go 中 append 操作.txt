### 解题思路

1. 使用 go 里面的强大的 append 函数

### 代码

```golang
func moveZeroes(nums []int)  {
	count := len(nums)
	for index := 0; index < count; index++ {
		if nums[index] == 0 {
			nums = append(nums[:index], append(nums[index+1:], 0)...)
			index--
			count--
		}
	}
}
```