# 递归实现
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
  var result []int
  preorder(root, &result)
  return result
}

func preorder(root *TreeNode, output *[]int) {
  if root != nil {
    *output = append(*output, root.Val)
    preorder(root.Left, output)
    preorder(root.Right, output)
  }
}
```

# 非递归实现
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
  var res []int
  if root == nil {
    return res
  }

  cur := root
  for cur != nil {
    if cur.Left == nil {
      res = append(res, cur.Val)
      cur = cur.Right
    } else {
      prev := cur.Left
      for prev.Right != nil && prev.Right != cur {
        prev = prev.Right
      }

      if prev.Right == nil {
        res = append(res, cur.Val)
        prev.Right = cur
        cur = cur.Left
      } else {
        prev.Right = nil
        cur = cur.Right
      }
    }
  }
  return res
}
```
