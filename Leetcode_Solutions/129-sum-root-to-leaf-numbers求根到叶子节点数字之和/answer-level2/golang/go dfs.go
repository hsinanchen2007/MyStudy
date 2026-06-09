
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.
1、先序遍历 根1->左2->左3 4 * 10 = 40+9 * 10 = 490+5 = 495
2、根1->左2->右3 4* 10  = 40+9 * 10 = 490+1= 491
3、根1->右2 4* 10 = 40 +0 = 40

```
func sumNumbers(root *TreeNode) int {
	sum := 0
	if root == nil {
		return sum
	}
	helperSum(root, &sum, 0)
	return sum
}

func helperSum(root *TreeNode, sum *int, numbers int) {
	if root.Left == nil && root.Right == nil {
		*sum += numbers*10 + root.Val
		return
	}
	if root.Left != nil {
		helperSum(root.Left, sum, numbers*10+root.Val)
	}
	if root.Right != nil {
		helperSum(root.Right, sum, numbers*10+root.Val)
	}
}
```
