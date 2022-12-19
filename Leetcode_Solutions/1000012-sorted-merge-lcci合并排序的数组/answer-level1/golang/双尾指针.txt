func merge(A []int, m int, B []int, n int)  {
	i := m-1
	j := n-1
	cur := m + n -1
	for ; i>=0 || j>=0 ; {
		if i < 0 {
			A[cur] = B[j]
			cur --
			j --
			continue
		}
		if j < 0 {
			A[cur] = A[i]
			cur --
			i --
			continue
		}
		if A[i] > B[j]{
			A[cur] = A[i]
			cur --
			i --
		} else {
			A[cur] = B[j]
			cur --
			j --
		}
	}
}