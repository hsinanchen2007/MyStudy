### 解题思路
1、先排序
2、再依次遍历数组元素，若当前元素小于等于它前一个元素，则将其变为前一个数+1。

### 代码

```golang
func minIncrementForUnique(A []int) int {
	sort.Ints(A)
	var move = 0
	for i := 1; i < len(A); i++ {
		if A[i] <= A[i-1] {
			var prev = A[i]
			A[i] = A[i-1] + 1
			move = move + A[i] - prev
		}
	}
	return move
}
```