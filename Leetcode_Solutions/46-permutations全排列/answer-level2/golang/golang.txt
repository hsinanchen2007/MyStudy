### 代码

```golang
func permute(nums []int) [][]int {
	res := make([][]int, 0)
	length := len(nums)
	if length == 0 {
		return append(res, make([]int, 0))
	}
	for i := 0; i < length; i++ {
		for _, line := range permute(append(append(make([]int, 0), nums[0: i]...), nums[i + 1:]...)) {
			res = append(res, append([]int{nums[i]}, line...))
		}
	}
	return res
}
```