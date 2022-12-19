对于[1, n]，如果以 i(1<i<n) 为root，那么根据BST的性质，[1, i-1] 的元素落在其左子树，[i+1, n]落在右子树，这就得到了一个递归关系，以i为root的bst数量为左子树和右子树进行任意组合的总数量  
```golang
func numTrees(n int) int {
	note = make([][]int, n+1)
	for i := 0; i <= n; i++ {
		note[i] = make([]int, n+1)
		note[i][i] = 1
	}

	return _numTrees(1, n)
}

var note [][]int

func _numTrees(l, r int) int {
	if l >= r { // 没有左子树或者没有右子树
		return 1
	}

	if note[l][r] > 0 {
		return note[l][r]
	}

	c := 0
	for i := l; i <= r; i++ {
		lc := _numTrees(l, i-1)
		rc := _numTrees(i+1, r)
		c += lc * rc // 左子树和右子树任意组合，可以有lc*rc
	}
	note[l][r] = c
	return c
}
```