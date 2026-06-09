### 解题思路
计数, 投票

### 代码

```golang
func majorityElement(nums []int) int {
	var pre = nums[0]
	var count = 1

	for i := 1; i < len(nums); i++ {
		if nums[i] == pre {
			count++
		} else {
			count--
			if count <= 0 {
				pre = nums[i]
				count = 1
			}
		}
	}
	return pre
}
```