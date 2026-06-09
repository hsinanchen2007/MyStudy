```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deleteNode(root *TreeNode, key int) *TreeNode {
    if root == nil{
        return nil
    }
    if key <root.Val{
        root.Left = deleteNode(root.Left,key)
        return root
    }else if key >root.Val{
        root.Right = deleteNode(root.Right,key)
         return root
    }else{  // root.Val == key
        //判断要删除结点有没有左右节点
        if root.Left == nil{
            return root.Right
        }
        
        if root.Right == nil{
            return root.Left
        }
        
        //root.Left 和root.Right 都不为空
        successor := mininum(root.Right)
        successor.Right = removeMin(root.Right)
        successor.Left = root.Left
        return successor
    }   
}

func mininum(node *TreeNode)*TreeNode{
    if node == nil{
        return nil
    }
    if node.Left == nil{
        return node
    }
    return mininum(node.Left)
}

func removeMin(node *TreeNode)*TreeNode{
    if node == nil{
        return nil
    }
    if node.Left == nil{
        return node.Right
    }
    node.Left = removeMin(node.Left)
    return node
}
```

```
