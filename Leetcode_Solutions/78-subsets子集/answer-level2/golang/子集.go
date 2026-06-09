### 解题思路
2^n

### 代码

```golang
func subsets(nums []int) [][]int {
	var n = uint(len(nums))
	res := make([][]int, 0, 1 << n)
	var i uint
	for i = 0; i < 1<<n; i++ {
		s := make([]int, 0)
		var j uint
		for j = 0; j < n; j++ {
			if i&(1<<j) != 0 {
				s = append(s, nums[j])
			}
		}
		res = append(res, s)
	}
	return res
}

```