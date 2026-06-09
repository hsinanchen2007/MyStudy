```
func maxSumBST(root *TreeNode) (rst int) {
	isBST(root, &rst)
	return rst
}

func isBST(root *TreeNode, maxSum *int) (is bool, sum, minVal, maxVal int) {
	if root == nil {
		return true, 0, math.MaxInt32, math.MinInt32
	}

	leftIs, leftSum, leftMin, leftMax := isBST(root.Left, maxSum)
	rightIs, rightSum, rightMin, rightMax := isBST(root.Right, maxSum)

	if leftIs && rightIs {
		if root.Val > leftMax && root.Val < rightMin {
			if root.Left == nil {
				leftMin = root.Val
			}
			if root.Right == nil {
				rightMax = root.Val
			}
			rootSum := root.Val + leftSum + rightSum
			if rootSum > *maxSum {
				*maxSum = rootSum
			}
			return true, rootSum, leftMin, rightMax
		}
		return false, max(leftSum, rightSum), math.MaxInt32, math.MinInt32
	} else {
		return false, max(leftSum, rightSum), math.MaxInt32, math.MinInt32
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```
