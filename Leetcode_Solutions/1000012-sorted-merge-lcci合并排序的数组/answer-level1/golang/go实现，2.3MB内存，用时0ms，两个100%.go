### 解题思路
这是看了一个双指针题解然后想了好久做出来的，之前想用python 3行代码实现，但是python修改实参很麻烦，就边学go边试着写。主要注意的是A和B中的指针如果一个到头越界后，把另外一个遍历添加在后面就行了。

### 代码

```golang
func merge(A []int, m int, B []int, n int)  {
    a_index := m - 1
	b_index := n - 1
	index1 := m + n - 1
	for ; index1 >= 0; index1-- {
		// if A[0] >= B[b_index] {
		// 	A = append(A[:m], B...)
		// 	return
		// }
		if a_index >= 0 && b_index >= 0 {
			if A[a_index] >= B[b_index] {
				A[index1] = A[a_index]
				a_index--
			} else {
				A[index1] = B[b_index]
				b_index--
			}
		} else {
			if a_index >= 0 {
				A[index1] = A[a_index]
				a_index--
			} else {
				A[index1] = B[b_index]
				b_index--
			}
		}
	}
}
```