### 解题思路
go中判断map中是否包含只需要v,ok := map[i]形式即可

### 代码

```golang
func twoSum(nums []int, target int) []int {
	if len(nums) <= 1 {
		return []int{}
	}

	tmp := make(map[int]int, len(nums))
	for i := 0; i < len(nums); i++ {
		t := target - nums[i]
		if value, ok := tmp[t]; ok && value != i {
    		res := make([]int, 2)
			res[0] = value
			res[1] = i
			return res
		}
		tmp[nums[i]] = i
	}

	return []int{}
}
```