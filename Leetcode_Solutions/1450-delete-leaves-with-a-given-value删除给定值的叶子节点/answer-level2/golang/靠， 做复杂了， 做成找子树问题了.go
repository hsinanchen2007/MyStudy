### 解题思路
此处撰写解题思路

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
func removeLeafNodes(root *TreeNode, target int) *TreeNode {
    if root == nil {
        return nil
    }

    if root.Left == nil && root.Right == nil  {
        if root.Val != target {
            return root
        }

        return nil 
    }
     
    result := 0 
    helper(root, nil, 0, target, &result) 
    if result == 0 {
        return root
    }
   
    return removeLeafNodes(root, target)

}

func helper(root, pre *TreeNode,index int, target int, result *int)  {
    if root == nil {
        return
    }

    if root.Left == nil && root.Right == nil {
        if root.Val == target { 
            *result++
            if index == 0 {
                pre.Left = nil
            }else {
                pre.Right =nil
            }
        }

        return 
    }

    helper(root.Left, root, 0, target, result)
    helper(root.Right, root, 1, target, result)
}
```