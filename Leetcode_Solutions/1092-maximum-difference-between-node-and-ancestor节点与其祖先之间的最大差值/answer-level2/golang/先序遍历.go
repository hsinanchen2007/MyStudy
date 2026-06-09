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
func maxAncestorDiff(root *TreeNode) int {
    if root==nil {
        return 0
    }
    result := 0  

    helper(root,root.Val ,root.Val , &result ) 
    return result
}

func helper(root *TreeNode, min int, max int , result *int) {
    if root == nil {
        return 
    } 

    *result = Max(Abs(min-root.Val), *result )
    *result = Max(Abs(max-root.Val), *result )

    min = Min(min, root.Val)
    max = Max(max, root.Val)  

    helper(root.Left, min, max, result )
    helper(root.Right, min, max, result )
}

func Min(i,j int )int {
    if i < j {
        return i
    }
    return j
}

func Max(i,j int)int {
    if i > j {
        return i
    }
    return j
}

func Abs(i int)int {
    if i > 0 {
        return i
    }
    return -i
}
```