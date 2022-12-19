### 解题思路
两层循环解决

### 代码

```golang
func smallerNumbersThanCurrent(nums []int) []int {
	ret := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		for j := 0; j < len(nums); j ++ {
			if j == i {
				continue
			}
			if nums[j] < nums[i] {
				ret[i]++
			}
		}
	}
	return ret
}
```