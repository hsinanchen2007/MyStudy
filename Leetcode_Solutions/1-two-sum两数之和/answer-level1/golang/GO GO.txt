### 解题思路
感觉自己一般般，没有想到map，不过应该也算一种不用map的思路，用时24ms。看了map才发现存在判断确实很快。

### 代码

```golang
func twoSum(nums []int, target int) []int {

	type Map struct {
		Index int
		Value int
	}

	var result []*Map
	for i := 0; i < len(nums); i++ {
		value := nums[i]
		for _, s := range result {
			if value+s.Value == target {
				return []int{s.Index, i}
			}
		}

		result = append(result, &Map{
			Index: i,
			Value: value,
		})
	}

	return nil
}
```