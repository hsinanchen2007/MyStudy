# 思考

递归方式：辅助函数findPorQ(root, p, q)以root为根的树，寻找p或q，找到哪个返回哪个。如果root==p或者root==q，直接return root，否则分别对左子树findPorQ(root.left, p, q)和右子树进行递归findPorQ(root.right, p, q)。

## 二叉搜索树的最近公共祖先

因为是二叉搜索树，二叉搜索树的特性是 **左节点<= 当前结点<= 右节点**。

所以如果满足二叉搜索树的这个特性即 p.Val <= root.Val <= q.Val，那么说明该节点就是p和q的公共祖先。

如果不符合，那就根据p和q的值判断去左子树找还是右子树找。

```go
/**
 * Definition for TreeNode.
 * type TreeNode struct {
 *     Val int
 *     Left *ListNode
 *     Right *ListNode
 * }
 */
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if p.Val > q.Val {
    	p, q = q, p
    }
    
    if root == nil || p.Val <= root.Val && root.Val <= q.Val {  
        return root
    } else if q.Val <= root.Val {
        return lowestCommonAncestor(root.Left, p, q)
    } else {
        return lowestCommonAncestor(root.Right, p, q)
    }
}
```

## 二叉树的最近公共祖先-通用解法

```go
/**
 * Definition for TreeNode.
 * type TreeNode struct {
 *     Val int
 *     Left *ListNode
 *     Right *ListNode
 * }
 */
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    // 找到了一个节点，返回那个节点，或者找到了叶子节点，直接返回
    if root == p || root == q || root == nil {  
        return root
    }
    // 如果该子树下包含要找的节点，那么返回该节点地址，否则返回 nil
    l := lowestCommonAncestor(root.Left,p,q)  
    r := lowestCommonAncestor(root.Right,p,q)
    if l!=nil && r!=nil {  
        return root
    } else if l != nil { 
        return l
    } else if r != nil {
        return r
    }
    return nil  
}
```

学习自大佬[@elliotxx](/u/elliotxx)