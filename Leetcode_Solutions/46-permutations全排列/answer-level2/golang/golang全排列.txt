### 解题思路
用dfs算法来找到全排列，编写代码的时候可以利用golang闭包的性质，减少dfs函数的参数，同时也可以减少内存消耗

注意深拷贝的坑

### 代码

```golang
func permute(nums []int) [][]int {
	var (
		result  [][]int
		res     = make([]int, len(nums))
		visited = make([]bool, len(nums))
		dfs     func(int)
	)
	dfs = func(depth int) {
		if depth == len(nums) {
			tmp := make([]int, len(res))
			copy(tmp, res)
			result = append(result, tmp)
			return
		}
		for i := 0; i < len(nums); i++ {
			if !visited[i] {
				visited[i] = true
				res[depth] = nums[i]
				dfs(depth + 1)
				visited[i] = false
			}
		}
	}
	dfs(0)
	return result
}
```