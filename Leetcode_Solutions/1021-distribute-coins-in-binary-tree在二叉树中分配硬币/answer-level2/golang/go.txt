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
 
func distributeCoins(root *TreeNode) int {
    v := 0
    cost(root,&v)
    return v
}

func cost(root *TreeNode,sum *int) int {
    if root == nil{
        return 0
    }
    l := cost(root.Left,sum)
    r := cost(root.Right,sum)
    *sum = *sum + abs(l) + abs(r)
    return l+r+root.Val-1
}

func abs(v int)int{
    if v >= 0{
        return v
    }
    return -v
}
```