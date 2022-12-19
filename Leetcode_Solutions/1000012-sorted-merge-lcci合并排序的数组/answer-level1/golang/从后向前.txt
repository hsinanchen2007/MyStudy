因为数组容量肯定够用，直接在 A 数组上从后向前插入即可
使用三指针，分别针对 A 的有效数据尾部、在 A 上的插入插入位置、B 的尾部，在循环中分别向前移动这三个指针并整合即可

```go
// 执行耗时:0 ms,击败了100.00% 的Go用户
// 内存消耗:2.3 MB,击败了100.00% 的Go用户
func merge(A []int, m int, B []int, n int) {
	pa := m - 1
	pb := n - 1
	tail := m + n - 1
	for tail >= 0 && pb >= 0 && pa >= 0 {
		if A[pa] <= B[pb] {
			A[tail] = B[pb]
			pb--
		} else {
			A[tail] = A[pa]
			pa--
		}
		tail--
	}
	for pb >= 0 && tail >= 0 {
		A[tail] = B[pb]
		pb--
		tail--
	}
}
```