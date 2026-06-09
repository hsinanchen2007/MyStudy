BFS在最理想的情况下，可以在第二层就找到答案（假设树最小深2）。最坏情况也仅需要O(N)时间复杂度。空间则是O(N)的。DFS则每次都需要O(N)。

```go
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    var depth int
    trees := []*TreeNode{root}
    for len(trees) > 0 {
        var temp []*TreeNode
        for _,tree := range trees{
            if tree.Left == nil && tree.Right == nil {
                return depth + 1
            }
            if tree.Left != nil{
                temp = append(temp,tree.Left)
            }
            if tree.Right != nil{
                temp = append(temp,tree.Right)
            }
        }
        depth++
        trees = temp
    }
    return depth
}
```
