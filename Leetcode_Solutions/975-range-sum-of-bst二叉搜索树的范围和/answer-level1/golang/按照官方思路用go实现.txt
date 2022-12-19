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

var sum int

func rangeSumBST(root *TreeNode, L int, R int) int {
    sum = 0
    dfs(root, L, R)
    return sum
}

func dfs(node *TreeNode, L int, R int) {
    if node != nil {
        if node.Val >= L && node.Val <= R {
                sum += node.Val
                dfs(node.Left, L, R)
                dfs(node.Right, L, R)
            }
            if node.Val < L {
                dfs(node.Right, L, R)
            }
            if node.Val > R {
                dfs(node.Left, L, R)
            }
    }
   
}

```