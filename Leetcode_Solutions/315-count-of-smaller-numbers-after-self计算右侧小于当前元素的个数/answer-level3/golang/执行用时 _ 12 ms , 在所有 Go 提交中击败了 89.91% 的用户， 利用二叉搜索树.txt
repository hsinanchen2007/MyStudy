### 解题思路
利用二叉搜索树，建树的过程把树的左子树节点数量算出来，插入右边节点时就可以算出比当前节点小的个数了
左子树加定点，（遍历过的所有定点累加）

### 代码

```golang
type TreeNode struct {
	Val   int
	Count int // 左子树的个数
	Left  *TreeNode
	Right *TreeNode
}

func BST_insert(node *TreeNode, insert_node *TreeNode, small_count *int) {
	// 放在左边
	if insert_node.Val <= node.Val {
		node.Count++
		if node.Left != nil {
			BST_insert(node.Left, insert_node, small_count)
		} else {
			node.Left = insert_node
		}
	}
	if insert_node.Val > node.Val {
		*small_count = *small_count + node.Count + 1
		if node.Right != nil {
			BST_insert(node.Right, insert_node, small_count)
		} else {
			node.Right = insert_node
		}
	}
}

func countSmaller(nums []int) []int {
	length := len(nums)
	count := make([]int, length)
	if length <= 1 {
		return count
	}

	// 从右往左处理
	node := TreeNode{Val: nums[length-1]}
	count[length-1] = 0

	for i := length - 2; i >= 0; i-- {
		var data int
		BST_insert(&node, &TreeNode{Val: nums[i]}, &data)
		count[i] = data
	}
	return count
}

```