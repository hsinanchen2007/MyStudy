### 解题思路
双指针

### 代码

```golang
func merge(A []int, m int, B []int, n int)  {
    // 将 A 复制一份
	ACopy := make([]int, m)
	copy(ACopy, A[:m])
	// 开始合并
	i, j := 0, 0
	k := 0
	for i < m && j < n {
		if ACopy[i] < B[j] {
			A[k] = ACopy[i]
			i++
			k++
		} else {
			A[k] = B[j]
			j++
			k++
		}
	}
	for i < m {
		A[k] = ACopy[i]
		i++
		k++
	}
	for j < n {
		A[k] = B[j]
		j++
		k++
	}
}
```