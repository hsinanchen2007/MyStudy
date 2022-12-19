```
//Bst 搜索特性解题
func findTarget(root *TreeNode, k int) bool {
	var num = []int{}
	bstTarget(root, &num)
	l, r := 0, len(num)-1
	for l < r {
		sum := num[l] + num[r]
		if sum == k {
			return true
		} else if sum < k {
			l++
		} else {
			r--
		}
	}
	return false
}
func bstTarget(root *TreeNode, num *[]int) {
	if root == nil {
		return
	}
	bstTarget(root.Left, num)
	*num = append(*num, root.Val)
	bstTarget(root.Right, num)
}
```
```
//hash map 特性
func findTarget(root *TreeNode, k int) bool {
	var hash = make(map[int]int)
	return dfsTarget(root, hash, k)
}
func dfsTarget(root *TreeNode, hash map[int]int, k int) bool {
	if root == nil {
		return false
	}
	if _, ok := hash[k-root.Val]; ok {
		return true
	}
	hash[root.Val] = 1
	return dfsTarget(root.Left, hash, k) || dfsTarget(root.Right, hash, k)
}
```

