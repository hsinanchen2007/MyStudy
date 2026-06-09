### 解题思路
如果两个节点的值都大于当前节点的值就在节点又子树，小于在左子树，否则就是当前节点
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
    if root == nil {
        return root
    }
    val := root.Val
    pVal := p.Val
    qVal := q.Val
    if p.Val > val && q.Val > val {
        return lowestCommonAncestor(root.Right, p, q)
    }
    if pVal < val && qVal < val {
        return lowestCommonAncestor(root.Left, p, q)
    }
    return root
}
```