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
func diameterOfBinaryTree(root *TreeNode) int {
    max := 0
    _ = depth(root,&max)
    if root == nil{
        return 0
    }
    return max-1
}
func depth(root *TreeNode, maxD *int) int{
    if root == nil{
        return 0
    }
    l := depth(root.Left,maxD)
    r := depth(root.Right,maxD)
    if l+r+1 > *maxD{
        *maxD = l+r+1
    }
    return max(l,r)+1
}

func max(a,b int) int{
    if a>b{
        return a
    }
    return b
}
```