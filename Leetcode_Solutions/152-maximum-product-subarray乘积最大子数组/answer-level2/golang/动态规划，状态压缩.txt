第一种解法：暴力求解（可能会超时）

执行用时 :108 ms, 在所有 golang 提交中击败了11.00%的用户
内存消耗 :2.7 MB, 在所有 golang 提交中击败了65.75%的用户

```
func maxProduct4(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	temp := 1
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		temp = 1
		for j := i; j < len(nums); j++ {
			temp *= nums[j]
			if res < temp {
				res = temp
			}
		}
	}
	return res
}
```


第二种解法：DP

执行用时 :4 ms, 在所有 Go 提交中击败了95.09%的用户
内存消耗 :2.7 MB, 在所有 Go 提交中击败了63.01%的用户

```
func maxProduct(nums []int) int {
    temp0, temp1, res := nums[0], nums[0], nums[0]
	for i:=0; i<len(nums)-1; i++ {
		if nums[i+1] >= 0 {
			temp0, temp1 = max(temp0 * nums[i+1], nums[i+1]), min(temp1 * nums[i+1], nums[i+1])
		} else {
			temp0, temp1 = max(temp1 * nums[i+1], nums[i+1]), min(temp0 * nums[i+1], nums[i+1])
		}
		if res < temp0 {
			res = temp0
		}
	}
	return res
}

func max(a int, b int) int {
	if a > b{
		return a
	}
	return b
}

func min(a int, b int) int {
	if a > b{
		return b
	}
	return a
}
```
