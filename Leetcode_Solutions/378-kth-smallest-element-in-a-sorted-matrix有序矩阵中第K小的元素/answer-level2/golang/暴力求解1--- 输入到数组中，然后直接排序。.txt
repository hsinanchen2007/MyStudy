### 解题思路

本文来自公众号 ：**算法和数据结构的峡谷**

此解体方法虽然解题的方法简单，也容易理解，但是时间复杂度很不香，空间复杂度也不香。适合刚学习算法的小白看。


### 代码

```golang
// 各种解体方法1 多路归并 2 堆 3 二分 4 求每列最小值

// 暴力求解 时间复杂度 nm + nmlognm(go默认大数据是快排); 空间复杂度是 nm
func kthSmallest(matrix [][]int, k int) int {
	if len(matrix) == 0 {
		return 0
	}

	l := make([]int, len(matrix)*len(matrix[0]))
	t := 0
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			l[t] = matrix[i][j]
			t++
		}
	}
	sort.Ints(l)
	return l[k-1]
}

```