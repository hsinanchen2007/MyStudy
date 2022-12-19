Go: 0ms(100%), 2.9MB(58%)
  
**思路**：非递归前序遍历将节点放入数组中，然后遍历数组，将每个节点元素的左孩子置空，右孩子指向下一个元素节点

```go
func flatten(root *TreeNode)  {
    if root == nil || (root.Left == nil && root.Right == nil) {
        return
    }
    nodes := make([]*TreeNode, 0)
    stack := make([]*TreeNode, 0)
    node := root
    stack = append(stack, node)
    for len(stack) != 0 {
        node = stack[len(stack) - 1]
        nodes = append(nodes, node)
        stack = stack[: len(stack) - 1]
        if node.Right != nil {
            stack = append(stack, node.Right)
        }
        if node.Left != nil {
            stack = append(stack, node.Left)
        }
    }

    for i := 1; i < len(nodes); i++ {
        nodes[i - 1].Left = nil
        nodes[i - 1].Right = nodes[i]
    }
    nodes[len(nodes) - 1].Left = nil
}
```
