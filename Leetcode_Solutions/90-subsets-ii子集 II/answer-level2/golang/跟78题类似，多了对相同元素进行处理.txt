### 解题思路
1. 先对代码进行排序，使相同的元素相邻
2. 对相同元素进行统一处理，先得到相同元素的个数count，分别添加1, ..., count个相同元素到当时集合中

### 代码

```golang
func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)
	var ans = make([][]int, 0)
	ans = append(ans, []int{})
	for i := 0; i < len(nums); i++ {
		var l = len(ans)
		// 找出和当前元素nums[i]相同的个数
		var count int = 1
		for x := i + 1; x < len(nums); x++ {
			if nums[x] == nums[i] {
				count++
			} else {
				break
			}
		}
		for j := 0; j < l; j++ {
			// 根据count的值添加count个元素
			for y := 0; y < count; y++ {
				var data = make([]int, len(ans[j]) + y + 1)
				for k, v := range ans[j] {
					data[k] = v
				}
				for z := len(ans[j]); z < len(ans[j]) + y + 1; z++ {
					data[z] = nums[i]
				}
				ans = append(ans, data)
			}
		}
		// 跳过后面跟nums[i]相同的元素
		i += count - 1
	}
	return ans
}
```