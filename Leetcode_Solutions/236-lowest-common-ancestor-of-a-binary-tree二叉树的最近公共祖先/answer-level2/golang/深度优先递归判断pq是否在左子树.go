### 解题思路
深度优先递归判断pq是否在左子树
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
     if root == nil || root == p || root == q {
         return root
     }
     // 找到p和q的path，然后比较相同的
     leftp := findNode(root.Left, p)
     leftq := findNode(root.Left, q)
     if leftp && leftq {
         return lowestCommonAncestor(root.Left, p, q)
     } else if !leftp && !leftq {
        return lowestCommonAncestor(root.Right, p, q)
     }
     return root
}

func findNode(root *TreeNode, node *TreeNode) bool {
    if root == nil {
        return false
    }
    if root == node {
        return true
    }
    left := false
    if root.Left != nil {
        left = findNode(root.Left, node)
    }
    if !left && root.Right != nil {
        return findNode(root.Right, node)
    }
    return left
}
```