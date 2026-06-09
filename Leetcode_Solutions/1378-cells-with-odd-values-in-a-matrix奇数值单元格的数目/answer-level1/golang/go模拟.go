### 解题思路
模拟

### 代码

```golang
// 统计变换后的数组中奇数的个数
func oddCells(n int, m int, indices [][]int) int {
    nums := make([][]int,n)
    for i := 0; i < n; i++{
        nums[i] = make([]int, m)
    }
	for i := 0; i < len(indices); i++ {
		for j := 0; j < m; j++ {
			nums[indices[i][0]][j]++
		}
		for k := 0; k < n; k++ {
			nums[k][indices[i][1]]++
		}
	}
	res := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if nums[i][j]%2 == 1 {
				res++
			}
		}
	}
	return res
}

```