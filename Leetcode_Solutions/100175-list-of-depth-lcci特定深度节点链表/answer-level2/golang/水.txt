### 解题思路
dfs跑一跑

### 代码

```golang
func listOfDepth(tree *TreeNode) []*ListNode {
	res := []*ListNode{}
	dfs(tree, 0, &res)
	return res
}

func dfs(node *TreeNode, level int, res *[]*ListNode) {
	if node == nil {
		return
	}
	if level >= len(*res) {
		*res = append(*res, &ListNode{
			Val: node.Val,
		})
	} else {
		now := (*res)[level]
		for now.Next != nil {
			now = now.Next
		}
		now.Next = &ListNode{
			Val: node.Val,
		}
	}
	dfs(node.Left, level+1, res)
	dfs(node.Right, level+1, res)
}

```