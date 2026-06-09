## 前言
解题思路可以参考官方的解题，本解题只是展示如何使用go实现

## 暴力法
```
func twoSum(nums []int, target int) []int {
	length := len(nums)
	for i := 0; i < length; i++ {
		for j := i+1; j < length; j++ {
			if nums[i]+nums[j] == target {
				result := []int{i,j}
				return result
			}
		}
	}
	return nil
}
```

## 两遍哈希表法
```
func twoSum(nums []int, target int) []int {
	numMap := make(map[int]int)
	length := len(nums)
	for i := 0; i < length; i++ {
		numMap[nums[i]] = i
	}
	for j := 0; j < length; j++ {
		complement := target - nums[j]
		if v, contains := numMap[complement]; contains && v != j {
			return []int{j, v}

		}
	}
	return nil
}
```