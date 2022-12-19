### 解题思路
此处撰写解题思路
要获取两个数下标，首先想到使用两个for循环遍历所有下标的组合，类似数组的升序或者降序排序，加上判断即可找出结果。
### 代码

```golang
func twoSum(nums []int, target int) []int {
	var result []int
	for i := 0; i < len(nums)-1; i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				result = []int{i, j}
			}
		}
	}

	return result
}
```