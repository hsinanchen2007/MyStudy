### 解题思路
不需要额外的空间，只在原来A的数组上原地操作即可。
Logic类似MergeSort，只不过从两个数组的有效数据尾部开始。
大的数自动放到A数组的尾部，尾部索引-1，移动的数组索引-1。
循环的终止条件是A或者B其中一个数组全部移走完毕。
最后将另一个数组剩余的部分放在数组前面。

### 代码

```golang

func merge(A []int, m int, B []int, n int) {
	idx := len(A) - 1
	sA, sB := m-1, n-1

	for sA >= 0 && sB >= 0 {
		if A[sA] > B[sB] {
			A[idx] = A[sA]
			sA--
		} else {
			A[idx] = B[sB]
			sB--
		}
		idx--
	}
	if sA >= 0 {
		for i := sA; i >= 0; i-- {
			A[idx] = A[i]
			idx--
		}
	}
	if sB >= 0 {
		for i := sB; i >= 0; i-- {
			A[idx] = B[i]
			idx--
		}
	}
}

```