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
func isCousins(root *TreeNode, x int, y int) bool {
    helper(root, 0, 0, x,y)
    fmt.Println(d1,d2,p1,p2)
    return d1 == d2 && p1 != p2
}
var d1,d2,p1,p2 int

func helper(root *TreeNode, rootVal int, depth int,x,y int) {
    if root == nil {
        return
    }
    if root.Val == x {
        p1 = rootVal
        d1 = depth
    }
    if root.Val == y {
        p2 = rootVal
        d2 = depth
    }
    helper(root.Left, root.Val , depth+1, x, y)
    helper(root.Right, root.Val , depth+1, x, y)
}
//        1 
//    2      3 
// nil 4 nil 5

```