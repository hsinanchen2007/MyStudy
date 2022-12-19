### 解题思路
子树抢不抢构成了父节点抢不抢

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
func rob(root *TreeNode) int {
    // 动态规划
    // dp[i][0] = max(dp[2* i + 1][0], dp[2 * i + 1][1]) + max(dp[2i+2][0], dp[2i + 2][1])
    // dp[i][1] = m[i] + dp[2* i + 1][0] + dp[2i+2][0]
    // 如果是数组表示的树一次循环就可以，二叉树则用递归
    non, rob := robTree(root)
    return max(non, rob)
}

func robTree(root *TreeNode) (int, int) {
    if root == nil {
        return 0, 0
    }
    // 左子树
    ln, lr := robTree(root.Left)
    // 右子树
    rn, rr := robTree(root.Right)
    // 不抢, 抢
    return max(ln, lr) + max(rn, rr), root.Val + ln + rn
}

func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}
```