### 解题思路
中序遍历

### 代码

```golang
type BSTIterator struct {
	values []int
	index  int
}

func Constructor(root *TreeNode) BSTIterator {
	vals := make([]int, 0)
	inorder(root, &vals)
	return BSTIterator{
		values: vals,
		index:  0,
	}
}

/** @return the next smallest number */
func (bi *BSTIterator) Next() int {
	val := bi.values[bi.index]
	bi.index++
	return val
}

/** @return whether we have a next smallest number */
func (bi *BSTIterator) HasNext() bool {
	return bi.index < len(bi.values)
}

func inorder(root *TreeNode, values *[]int) {
	if root == nil {
		return
	}
	inorder(root.Left, values)
	*values = append(*values, root.Val)
	inorder(root.Right, values)
}

```