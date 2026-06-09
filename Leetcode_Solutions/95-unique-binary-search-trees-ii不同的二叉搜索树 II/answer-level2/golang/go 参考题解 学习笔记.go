```
func generateTrees(n int) []*TreeNode {
	if n == 0 {
		return nil
	}
	return dfsgenerateTrees(1, n)
}
func dfsgenerateTrees(start, end int) []*TreeNode {
	var (
		helper []*TreeNode
	)
	if start > end {
		helper = append(helper, nil)
		return helper
	}
	for i := start; i <= end; i++ {
		for _, l := range dfsgenerateTrees(start, i-1) {
			for _, r := range dfsgenerateTrees(i+1, end) {
				node := &TreeNode{
					Val: i,
				}
				node.Left = l
				node.Right = r
				helper = append(helper, node)
			}
		}
	}
	return helper
}
```
