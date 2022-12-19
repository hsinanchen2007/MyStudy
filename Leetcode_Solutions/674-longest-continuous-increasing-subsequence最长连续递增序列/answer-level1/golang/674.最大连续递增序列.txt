### 解题思路

遍历数组，记录最长的连续递增序列即可。

### 代码

```golang
func findLengthOfLCIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	res,l := 1,1
	for i := 1;i < len(nums);i++ {
		if nums[i] <= nums[i - 1] {
			if l > res {
				res = l
			}
			l = 1
			continue
		}
		if nums[i] > nums[i - 1]{
			l++
		}
		if i == len(nums) - 1 {
			if l > res {
				res = l
			}
		}
	}
	return res
}
```