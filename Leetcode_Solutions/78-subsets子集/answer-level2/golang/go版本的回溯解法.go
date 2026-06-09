### 解题思路
可以看成从集合从取出i个不同的元素的取法其中 i>=0 && i<= len(nums)

执行用时 : 0 ms , 在所有 Go 提交中击败了 100.00% 的用户
内存消耗 : 2.3 MB , 在所有 Go 提交中击败了 99.12% 的用户
### 代码

```golang
func subsets(nums []int) [][]int {
   ans := make([][]int, 0)

	var backtrace func(pos, num int, cur []int)
	backtrace = func(pos, num int, cur []int) {
		if len(cur) == num {
			tmp := make([]int, len(cur))
			copy(tmp, cur)
			ans = append(ans, tmp)
			return
		}

		for i := pos; i < len(nums); i++ {
			cur = append(cur, nums[i])
			backtrace(i+1, num, cur)
			cur = cur[:len(cur)-1]
		}
	}

	for i := 0; i <= len(nums); i++ {
		cur := make([]int, 0, i)
		backtrace(0, i, cur)
	}

	return ans
}
```