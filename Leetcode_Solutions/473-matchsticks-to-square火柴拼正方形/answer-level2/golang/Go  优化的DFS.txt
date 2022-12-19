### 解题思路
深度优先搜索问题,要做一定的剪枝优化

DFS前做优化，选择时做优化



框架 
```go
func DFS{
	// 退出条件

	for i:=0;xxxx;xxx{
		
		// 选择
		DFS
		// 取消选择	
	}

}
```
### 代码

```golang
func makesquare(nums []int) bool {

	if len(nums) < 4 {
		return false
	}
	var sum int
	for i := 0; i < len(nums); i++ {
		sum += nums[i]
	}
	if sum%4 != 0 {
		return false
	}
	target := sum / 4
	// 倒排能优先过滤掉不符合条件的情况
	sort.Ints(nums)
	length := len(nums)
	numsss := make([]int, length)
	j := 0
	for i := len(nums) - 1; i >= 0; i-- {
		numsss[j] = nums[i]
		j++
	}

	position := make([]int, 4)
	res := DFS(position, numsss, 0, target)
	return res
}
func DFS(position, nums []int, index, target int) bool {
	if index >= len(nums) {
		return position[0] == position[1] && position[1] == position[2] && position[2] == position[3]
	}
	for i := 0; i < 4; i++ {
		// 选择时做优化，注意这里是continue，总共有4个选择，跳过这个选择，不是break或者return
		if position[i]+nums[index] > target {
			continue
		}
		// 做选择
		position[i] += nums[index]

		res := DFS(position, nums, index+1, target)
		if res {
			return true
		}
		//取消选择
		position[i] -= nums[index]
	}
	return false
}

```