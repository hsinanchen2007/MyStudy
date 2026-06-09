### 解题思路

这是根据伟大的[💖💖💖💖💖花花酱视频解说](http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-312-burst-balloons/)的思路和代码改写的Golang代码。

**侵删**

我们分解这个大的问题为小问题。
用一个2D数组来`c`来记录答案，`c[i][j]`表示从i到j的最佳收益。

为了方便，可以先对输入`nums`前后padding`1`。

DP状态转移方程的填充过程：

1.  我们的仔问题的长度从`1`开始，逐渐寻找长度为`n`的子问题的答案。
2.  子问题开始的位置是`i=1`, 结束的位置`j=i+l-1`。
3.  在子问题中，我们从第一个位置开始逐渐打破每一个`k`。
4.  因此`c[i][j]`就可以通过`c[i][j] = max(c[i][j], c[i][k-1]+nums[i-1]*nums[k]*nums[j+1]+c[k+1][j])`这个状态转移方程求得。

### 代码

```golang
func maxCoins(nums []int) int {
	// Store the input's length.
	n := len(nums)
	// Padding 1s to head and tail of nums.
	nums = append(nums, 1)
	nums = append([]int{1}, nums...)

	// Create 2D-DP with n+2 width and height.
	// c[i][j] represents the max coins from i to j.
	c := make([][]int, n+2)
	for i := range c {
		c[i] = make([]int, n+2)
	}

	// l is the length of subarray. We start with l= 1, end with l = n.
	for l := 1; l <= n; l++ {
        // i is the start point in this subarray.
		for i := 1; i <= n-l+1; i++ {
            // j is the subarray's end.
            j := i + l - 1
            // k is the break point to separate.
			for k := i; k <= j; k++ {
				c[i][j] = max(c[i][j], c[i][k-1]+nums[i-1]*nums[k]*nums[j+1]+c[k+1][j])
			}
		}
	}

	return c[1][n]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

```