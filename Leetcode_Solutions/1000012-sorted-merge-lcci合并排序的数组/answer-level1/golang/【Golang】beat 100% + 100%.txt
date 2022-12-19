### 解题思路

使用指针A、指针B分别指向数组A、数组B的最大值。
指针M指向数组A的末尾。

从大到小填充数据即可。

### 代码

```golang
func merge(A []int, m int, B []int, n int) {
	pointerA, pointerB, pointerM := m-1, n-1, m+n-1
	for pointerA >= 0 && pointerB >= 0 {
		if A[pointerA] > B[pointerB] {
			A[pointerM] = A[pointerA]
			pointerA--
		} else {
			A[pointerM] = B[pointerB]
			pointerB--
		}
		pointerM--
	}

	for pointerB >= 0 {
		A[pointerM] = B[pointerB]
		pointerB--
        pointerM--
	}
}
```