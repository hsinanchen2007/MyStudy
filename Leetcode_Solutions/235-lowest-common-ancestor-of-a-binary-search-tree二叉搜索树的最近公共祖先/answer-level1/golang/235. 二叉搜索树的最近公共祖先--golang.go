### 解题思路
根据搜索二叉树的性质即可得出结论

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
        return nil
    }

    min := p.Val
    max := q.Val
   if min > max {
       min , max  = max , min
   }
   
    return Run(root,min,max)
}

func Run(root *TreeNode,min,max int) *TreeNode{
    if root == nil {
        return nil
    }

    if min < root.Val && max > root.Val {
        return root
    }
    if min == root.Val && max > root.Val {
        return root
    }
    if max == root.Val && min < root.Val {
        return root
    }
    res := Run(root.Left,min,max)
    if res != nil {
        return res
    }
    res = Run(root.Right,min,max)
    if res != nil {
        return res
    }
    return nil   
}
    
```