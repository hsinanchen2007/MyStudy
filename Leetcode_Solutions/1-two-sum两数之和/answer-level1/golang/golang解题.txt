### 解题思路
此处撰写解题思路

### 代码

```golang
func twoSum(nums []int, target int) []int {
    map_ := map[int]int{}
	for index, num := range nums {
		map_[num] = index
	}
	for index, num := range nums {
		result := target - num
		if val, ok := map_[result]; ok && val != index {
			return []int{index, val}
		}
	}
	return []int{}
}
```