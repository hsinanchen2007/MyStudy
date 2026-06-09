
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
func mirrorTree(root *TreeNode) *TreeNode {
    if root ==nil{
        return nil
    }
    queue := list.New()
    queue.PushFront(root)
    for queue.Len()>0{
        node := queue.Remove(queue.Back()).(*TreeNode)
         temp := node.Left
        node.Left = node.Right
        node.Right = temp
        if node.Left != nil {   
             queue.PushFront(node.Left)
        }
        if node.Right != nil  {
            queue.PushFront(node.Right)
        }
    }
    return root
}
```