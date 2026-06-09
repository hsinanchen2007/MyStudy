### 解题思路

从树的根节点开始和两个节点作比较，如果当前节点的值比两个节点的值都大，则这两个节点的最近公共祖先节点一定在该节点的左子树中，则下一步遍历当前节点的左子树；

如果当前节点的值比两个节点的值都小，则这两个节点的最近公共祖先节点一定在该节点的右子树中，下一步遍历当前节点的右子树；这样直到找到第一个值是两个输入节点之间的值的节点，该节点就是两个节点的最近公共祖先节点。

### 代码

```golang
/**
 * Definition for TreeNode.
 * type TreeNode struct {
 *     Val int
 *     Left *ListNode
 *     Right *ListNode
 * }
 */
 func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
  
	if root.Val < p.Val && root.Val < q.Val {
		return lowestCommonAncestor(root.Right, p, q)
	} else if root.Val > p.Val && root.Val > q.Val {
		return lowestCommonAncestor(root.Left, p, q)
	} else {
		return root
	}
}
```