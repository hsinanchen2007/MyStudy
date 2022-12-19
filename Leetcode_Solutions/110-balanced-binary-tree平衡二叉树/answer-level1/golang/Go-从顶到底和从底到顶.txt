两种方法：
1.从顶到底：
该方法是从顶到底进行判断，先判断当前节点是否平衡（分别求出左子树和右子树的高度，然后比较是否相差大于1），然后进行递归判断左子树和右子树是否平衡。
该方法的时间复杂度为O(nlogn)，缺陷是每个节点的高度会重复计算
```
func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	left := getHeight(root.Left)
	right := getHeight(root.Right)
	nodeBalanced := false
	if math.Abs(float64(left-right)) < float64(2) {
		nodeBalanced = true
	}
	return nodeBalanced && isBalanced(root.Left) && isBalanced(root.Right)
}

func getHeight(root *TreeNode) int {
	if root == nil {
		return -1
	}
	left := getHeight(root.Left)
	right := getHeight(root.Right)
	height := left
	if left < right {
		height = right
	}
	return height + 1
}
```
![image.png](https://pic.leetcode-cn.com/9482183d65b5acac767543a1b76d8c156db0e18c51cb9d0b4c557c8296de9dfb-image.png)


2.从底到顶：
从底到顶返回节点的最大高度。
```
func isBalanced(root *TreeNode) bool {
	isBalanced, _ := isBalancedHelper(root)
	return isBalanced
}

func isBalancedHelper(root *TreeNode) (nodeBalanced bool, nodeHeight int) {
	if root == nil {
		return true, -1
	}
	leftBalanced, leftHeight := isBalancedHelper(root.Left)
	rightBalanced, rightHeight := isBalancedHelper(root.Right)
	if leftBalanced && rightBalanced {
		if math.Abs(float64(leftHeight-rightHeight)) < float64(2) {
			nodeBalanced = true
		}
	}
	nodeHeight = int(math.Max(float64(leftHeight), float64(rightHeight))) + 1
	return nodeBalanced, nodeHeight
}
```
![image.png](https://pic.leetcode-cn.com/ca397be5850d62d7bcaf18ade3e57e119d2c76ce742645be4aed907f1877afba-image.png)
