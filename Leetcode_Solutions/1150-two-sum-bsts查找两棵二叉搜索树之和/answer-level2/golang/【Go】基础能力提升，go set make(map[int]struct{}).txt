```
var treeSet map[int]struct{} = make(map[int]struct{})

func oneBST(root1 *TreeNode) {
	if root1 == nil {
		return
	}
	oneBST(root1.Left)
	treeSet[root1.Val] = struct{}{}
	oneBST(root1.Right)
}

func theOtherBST(root2 *TreeNode, target int) bool {
	if root2 == nil {
		return false
	}
	if !theOtherBST(root2.Left, target) {
		if _, ok := treeSet[target - root2.Val]; ok {
			return true
		}
		return theOtherBST(root2.Right, target)
	}
	return true
}

func twoSumBSTs(root1 *TreeNode, root2 *TreeNode, target int) bool {
	treeSet = make(map[int]struct{})
	oneBST(root1)
	if !theOtherBST(root2, target) {
		treeSet = make(map[int]struct{})
		oneBST(root2)
		return theOtherBST(root1, target)
	}
	return true
}
```
