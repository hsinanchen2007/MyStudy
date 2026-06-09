### 解题思路
借助两个flag实现

### 代码

```golang
func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	nSum := -math.MaxInt32
	nGreat := -math.MaxInt32
	for i := 0; i < len(nums); i++ {
		nSum += nums[i]
		if nums[i] > nSum {
			nSum = nums[i]
		}
		if nSum > nGreat {
			nGreat = nSum
		}
	}
	return nGreat
}
```