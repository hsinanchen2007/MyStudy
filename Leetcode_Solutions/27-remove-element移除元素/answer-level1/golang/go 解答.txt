![image.png](https://pic.leetcode-cn.com/00474527f27768a34187a8f61e0d1f4c797199aebc1482bce111c0de16e757e2-image.png)



```
func removeElement(nums []int, val int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 && nums[0] == val {
		nums = nums[:0]
		return 0
	}
	if len(nums) == 1 && nums[0] != val {
		return 1
	}
	index := 0
	for i := 0; i < len(nums); i++ {
		if val != nums[i] {
			nums[index] = nums[i]
			index++
		}
	}
	return index
}
```

