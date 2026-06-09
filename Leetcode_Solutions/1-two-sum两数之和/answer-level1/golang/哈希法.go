### 解题思路
此处撰写解题思路

### 代码

```golang
func twoSum(nums []int, target int) []int {
	indexMap := make(map[int]int)
	for i, v := range nums {
		other := target - v
		if j,ok := indexMap[other]; ok {
			return []int{i, j}
		} else {
			indexMap[v] = i
		}
	}
	return nil

}
```