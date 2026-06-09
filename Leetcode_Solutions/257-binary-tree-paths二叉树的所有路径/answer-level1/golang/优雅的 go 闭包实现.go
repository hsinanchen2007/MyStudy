
go 闭包时递归需要先声明，传递数组指教直接 append 即可。
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func binaryTreePaths(root *TreeNode) []string {
    var (
        result []string
        helper func(*TreeNode, string, *[]string)
    )

    helper = func(node *TreeNode, val string, paths *[]string) {
        if node == nil {
            return 
        }

        val += strconv.Itoa(node.Val)
        if node.Left == nil && node.Right == nil {
            *paths = append(*paths, val)
        } else {
            val += "->"
            helper(node.Left, val, paths)
            helper(node.Right, val, paths)
        }
    }

    helper(root, "", &result)
    return result
}

```
