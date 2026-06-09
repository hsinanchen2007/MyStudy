### 解题思路
比较土，递归 剪枝

### 代码

```golang

func helpfind(id, sum, avg int, nums []int) bool {
	if id >= len(nums) {
		return false
	}
	if nums[id] > avg {
		return false
	}
	if sum > avg {
		return false
	}
	if sum == avg || nums[id] == avg {
		return true
	}

	return helpfind(id+1, sum+nums[id], avg, nums) || helpfind(id+1, sum, avg, nums)
}
func canPartition(nums []int) bool {
	sum := 0
	for _, n := range nums {
		sum += n
	}
	if sum%2 != 0 {
		return false
	}
	avg := sum / 2
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] > nums[j]
	})
	//看能不能凑成avg
	return helpfind(0, 0, avg, nums)

}
```