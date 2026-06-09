```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumNumbers(root *TreeNode) int {
    s := postOrder(root)
    ans := 0
    for i := 0; i < len(s); i++ {
        n, _ := strconv.Atoi(s[i])
        ans += n
    }
    return ans
}

func postOrder(root *TreeNode) []string {
    if root == nil {
        return []string{}
    }

    if root.Left == nil && root.Right == nil {
        return []string{fmt.Sprintf("%d",root.Val)}
    }
    
    l := postOrder(root.Left)
    r := postOrder(root.Right)
    
    for i := 0; i < len(l); i++ {
        l[i] = fmt.Sprintf("%d%s", root.Val, l[i])
    }
    
    for i := 0; i < len(r); i++ {
        r[i] = fmt.Sprintf("%d%s", root.Val, r[i])
    }    
    
    res := append(l, r...)
    return res
}
```
