### 解题思路
1. `原地` =  `Morris遍历`（其实就改改指针）
2. Morris遍历 且不保持树结构就 等于 `链表` 了
3. 本题当然是 `Morris前序遍历`

[Go版本 Github](https://github.com/temporaries/leetcode)
[对应模板 Github](https://github.com/temporaries/leetcode/blob/master/templates/tree/preorder_morris_break.go)

### 代码

```golang
func flatten(root *TreeNode) *TreeNode {
	head := root
	var max *TreeNode

	for root != nil {
		if root.Left == nil {
			root = root.Right
		} else {
			max = root.Left
			for max.Right != nil {
				max = max.Right
			}

			root.Right, max.Right = root.Left, root.Right
            root.Left = nil
		}
	}
	return head
}
```