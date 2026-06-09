### 解题思路
参考官方解法的三维DP

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
func minCameraCover(root *TreeNode) int {
    // dp动态规划，每个节点有三个状态，2，安装摄像头，1，没有安装摄像头但是能被覆盖，0，没有被覆盖
    // 2 : 孩子不需要安装摄像头
    // 1 : 孩子至少有一个有摄像头
    // 0 : 孩子都没有摄像头，父节点也没有摄像头
    if root == nil {
        return 0
    }
    // 返回根节点的几种状态
    _, dp1, dp2 := dfs(root)
    // 返回1和2状态的最小值
    return minTwo(dp1, dp2)
}

func dfs(root *TreeNode) (int, int, int) {
    if root == nil {
        return 0, 0, 1000
    }
    ldp0, ldp1, ldp2 := dfs(root.Left)
    rdp0, rdp1, rdp2 := dfs(root.Right)

    // 该节点无摄像头，并且不被覆盖，子节点都是1状态
    dp0 := ldp1 + rdp1
    // 该节点无摄像头，子节点必须至少有一个有摄像头，另一个是1，2状态
    dp1 := minTwo(ldp2 + minTwo(rdp1, rdp2), rdp2 + minTwo(ldp1, ldp2))
    // 该节点有摄像头，子节点任一状态都可以
    dp2 := 1 + minThree(ldp0, ldp1, ldp2) + minThree(rdp0, rdp1, rdp2)
    return dp0, dp1, dp2
}

func minTwo(a, b int) int {
    if a <= b {
        return a
    }
    return b
} 

func minThree(a, b, c int) int {
    res := a
    if b < a {
        res = b
    }
    if c < res {
        res = c
    }
    return res
} 
```