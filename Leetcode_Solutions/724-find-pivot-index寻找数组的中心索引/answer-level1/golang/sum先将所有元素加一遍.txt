### 解题思路
考虑 0 个元素和 1 个元素的情况
之后将所有元素加起来，遍历时减去左边和当前值是否等于左边值，如果成立，返回中心索引

### 代码

```golang
func pivotIndex(nums []int) int {
	if len(nums) == 0 {
		return -1
	}
	if len(nums) == 1 {
		return 0
	}

	sum := 0
	for _,v := range nums {
		sum = sum + v
	}

	leftSum := 0
	for k,v := range nums {
		if leftSum == sum - v - leftSum {
			return k
		}
		leftSum += v
	}
	return -1
}
```