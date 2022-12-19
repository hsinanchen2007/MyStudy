### 解题思路
本题解来自公众号**算法和数据结构的峡谷**
> [了解更多](https://github.com/googege/GOFamily)

二分法就是每次都是一分为二，从而是log2n的时间复杂度，这道题为什么是return的l因为在&& matrix[i][j] <= mid 中
当等于的时候nt不是<k的情况下，r就要减去1，但是l是不需要的，所以这个时候的l就是mid，那么也是我们要找的值，而r是mid-1
所以不符合条件。这道题中 matrix[i][j] <= mid是关键，一定要有等于。


### 代码

```golang
func kthSmallest(matrix [][]int, k int) int {
	if len(matrix) <=0 {
		return 0
	}

	m, n := len(matrix), len(matrix[0])
	l, r := matrix[0][0], matrix[m-1][n-1]

	for l <= r {

		mid := l + (r-l)>>1  // 此处是为了防止out of index
		nt := 0 // 为了测试是第k小的左边还是右边。

		for i := 0; i < len(matrix); i++ {
			for j := 0; j < len(matrix[0]) && matrix[i][j] <= mid; j++ {
				nt++
			}
		}

		if nt < k {
			l = mid + 1
		} else {
			r = mid - 1
		}

	}

	return l
}
```