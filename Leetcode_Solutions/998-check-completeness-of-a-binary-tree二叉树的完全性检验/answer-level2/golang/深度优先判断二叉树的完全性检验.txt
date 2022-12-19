### 解题思路
此处撰写解题思路
深度优先遍历获取高度，根据高度判断

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isCompleteTree(root *TreeNode) bool {
	if root == nil {
		return true
	}

	result := make([]int, 0)
	// result = append(result,)
	if helper(root, 0, &result) == false {
		return false
	}

	if len(result) == 0 {
		return true
	}

	a := result[0]
	maxH := result[0]
	for i := range result {
		//保证左边比右边相等或更高
		if result[i] > a {
			return false
		}

		//当高度如果比整个树高少了两层
		if result[i] <= maxH-2 {
			return false
		}

		a = result[i]
	}
	return true
}

func helper(root *TreeNode, height int, result *[]int) (isComplete bool) {

	if root == nil {
		*result = append(*result, height)
		return true
	}

	if root.Left == nil && root.Right != nil {
		return false
	}

	leftC := helper(root.Left, height+1, result)
	if !leftC {
		return false
	}

	rightC := helper(root.Right, height+1, result)
	if !rightC {
		return false
	}

	return true
}


```