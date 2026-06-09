### 解题思路

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
func diameterOfBinaryTree(root *TreeNode) int {
    if root == nil{
        return 0
    }
    var (
        result = math.MinInt32
    )
    helper(root,&result)
    return result
}

func helper(root *TreeNode,result *int) int {
    if root == nil {
        return 0
    }
    left := helper(root.Left,result)
    right := helper(root.Right,result)
    if left + right > *result {
        *result = left + right
    }
    return getMax(left,right)+1
}

func getMax(i,j int) int {
    if i < j {
        return j
    }
    return i
}
```