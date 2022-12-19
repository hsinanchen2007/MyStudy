### 解题思路
1.采用先序遍历

2.对于叶子节点的判断:
``` golang
if root.Left == nil && root.Right == nil {
        s += strconv.Itoa(root.Val)
        *res = append(*res,s)
        return ""
    }
```

3.对于遍历选择的判断：
```go
if root.Left != nil {
        Run(res,root.Left,s)
    }
    if root.Right != nil {
        Run(res,root.Right,s)
    }

```





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
func binaryTreePaths(root *TreeNode) []string {
    res := make([]string,0)
    s := ""
    if root == nil {
        return res
    }

    
    Run(&res,root,s)
    return res
}


func Run(res *[]string,root *TreeNode,s string) string {
    
    if root.Left == nil && root.Right == nil {
        s += strconv.Itoa(root.Val)
        *res = append(*res,s)
        return ""
    }

    s += strconv.Itoa(root.Val)
    s += "->"
    if root.Left != nil {
        Run(res,root.Left,s)
    }
    if root.Right != nil {
        Run(res,root.Right,s)
    }

    return s
}

```