### 解题思路
使用map记录已经访问的元素

执行用时 : 0 ms , 在所有 Go 提交中击败了 100.00% 的用户
内存消耗 : 2.7 MB , 在所有 Go 提交中击败了 71.96% 的用户
### 代码

```golang
func permute(nums []int) [][]int {
	ans := make([][]int, 0)

	var dfs func(pos int, cur []int, used map[int]struct{})
	dfs = func(pos int, cur []int, used map[int]struct{}) {
		if pos == len(nums) {
			tmp := make([]int, len(cur))
			copy(tmp, cur)
			ans = append(ans, tmp)
			return
		}

		for i := 0; i < len(nums); i++ {
			if _, ok := used[nums[i]]; ok {
				continue
			}

			cur = append(cur, nums[i])
			used[nums[i]] = struct{}{}
			dfs(pos+1, cur, used)
			cur = cur[:len(cur)-1]
			delete(used, nums[i])
		}
	}

	cur := make([]int, 0, len(nums))

	used := make(map[int]struct{}, len(nums))
	dfs(0, cur, used)
	return ans
}
```