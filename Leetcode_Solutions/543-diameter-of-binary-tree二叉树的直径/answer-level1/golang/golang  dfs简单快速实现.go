### 解题思路
1. 二叉树的直径 就是 二叉树的最长路径(这条路径可以不经过根节点)
2. 子问题是什么 max{左子树的最长路径,右子树的最长路径,左子树的深度+右子树的深度}
3. 解决子问题似乎需要两次递归? 那就会右重复计算 所以可以考虑引入一个结构存储中间结果
4. 中间结果是什么? 就是子树的最长路径长度 因此仅需要一个变量就够了
5. 所以 递归就是求处其树的深度在更新全局变量的值即可

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
    res := 0
    dfs(root,&res)
    return res
}
func dfs(root *TreeNode,res *int) int {
    if root == nil{
        return 0
    }
    l := dfs(root.Left,res)
    r := dfs(root.Right,res)
    *res = max(*res,l+r)
    return max(l,r)+1
}
func max(a,b int)int{
    if a > b{
        return a
    }
    return b
}
```