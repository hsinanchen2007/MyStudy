### 解题思路
创建一个 map 来存放所有的数组元素，如果 nums[i] 跟 target-nums[i] 均存在该 map 中，则返回这两个数

### 代码

```golang
func twoSum(nums []int, target int) []int {
	var cases = make(map[int]int)
	for _, v := range nums {
		if _, ok := cases[v]; !ok {
			cases[v] = 1
		} else {
			cases[v] += 1
		}
	}

	var r = make([]int, 2)
	for i := 0; i < len(nums) && nums[i] <= target; i++ {
		if _, ok := cases[target-nums[i]]; ok {
			r[0] = nums[i]
			r[1] = target - nums[i]
			break
		}
	}
	return r
}
```