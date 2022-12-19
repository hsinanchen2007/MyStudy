### 解题思路
此处撰写解题思路

B的每一个元素从A的后面可以查询可以插入的位置
1. 如果比A的当前位置j的数值要小，A[j]的数值向后移动一位，A[j+1]=A[j]
2. 否则，就放进去
3. 注意j<0 的情况

### 代码

```golang

func merge(A []int, m int, B []int, n int) {

	if m == 0 {
		copy(A, B)
		return
	}

	if n == 0 {
		return
	}

	for i := 0; i < n; i++ {
		j := m-1
		for j >= 0 {
			if B[i] < A[j] {
				A[j+1] = A[j]
				j--
			} else {
				A[j+1] = B[i]
				m++
				break
			}
		}

		//B[i]比m中所有数都小
		if j < 0 {
			A[0] = B[i]
			m++
		}

	}

}
```