```
执行用时 : 0 ms , 在所有 golang 提交中击败了 100.00% 的用户
内存消耗 : 2.8 MB , 在所有 golang 提交中击败了 100.00% 的用户
```

```
func permute(nums []int) (final [][]int) {
	if len(nums) < 2 {
		return [][]int{nums}
	}

	rsts := permute(nums[1:])
	for _, rst := range rsts {
		for idx, _ := range rst {
			prefix := append(rst[:idx:idx], nums[0])
			full := append(prefix, rst[idx:]...)
			final = append(final, full)
		}
		final = append(final, append(rst, nums[0]))
	}

	return final
}
```
