### 解题思路
dfs求解：
第n位数的子集 = 第n-1位子集 * nums中一个不相同的数
为了避免重复子集：那么控制dfs只能往后扩展,同时也达到了减支的目的

### 代码

```golang
func subsets(nums []int) [][]int {
	ret := getSet(nums, []int{}, 0)
	ret = append(ret, []int{})
	return ret
}

func getSet(nums []int, data []int, index int) [][]int {
	size := len(data)
	curData := make([][]int, 0)
	for i := index; i < len(nums); i++ {
		one := make([]int, size+1)
		copy(one, data)
		one[size] = nums[i]
		curData = append(curData, one)

		// next
		nextData := getSet(nums, one, i+1)
		for j := 0; j < len(nextData); j++ {
			curData = append(curData, nextData[j])
		}

	}

	return curData
}
```