# 递归法
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
    var result []int
  postorder(root, &result)
  return result
}
func postorder(root *TreeNode, output *[]int) {
  if root != nil {
    postorder(root.Left, output)
    postorder(root.Right, output)
    *output = append(*output, root.Val)
  }
}
```

# 非递归法

```go
func postorderTraversal(root *TreeNode) []int {
  stack := make([]*TreeNode, 0)
  output := make([]int, 0)
  if root == nil {
    return output
  }
  stack = append(stack, root)
  for len(stack) > 0 {
    node := stack[len(stack)-1]
    stack = stack[:len(stack)-1]
    output = append(output, node.Val)
    if node.Left != nil {
      stack = append(stack, node.Left)
    }
    if node.Right != nil {
      stack = append(stack, node.Right)
    }
  }
  reverse(output)
  return output
}

func reverse(arr []int) {
  i, j := 0, len(arr)-1
  for i < j {
    arr[i], arr[j] = arr[j], arr[i]
    i++
    j--
  }
}
```
