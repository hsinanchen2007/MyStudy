### 解题思路
1. 二叉树问题 先想到递归
2. 递归基 是 root 为 nil
3. 子问题 是 返回 子树最大和
4. 全局最大和 等于 [左右子树中的最大和与根节点之和 根节点 左右子树的最大和与根节点三者之和] 这三种情况中最大的值
5. 而子树最大和 仅可能是 [左右子树中的最大和与根节点之和 根节点] 这两种情况之一
6. 并且当出现负数的时候应该忽略 (与连续子数组最大的和的思路一致)

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
func maxPathSum(root *TreeNode) int {
    if root == nil{
        return 0
    }
    res := ^int(^uint(0)>>1)
    dfs(root,&res)
    return res
}
func dfs(root *TreeNode, res *int)int{
    if root == nil{
        return 0
    }
    left := dfs(root.Left,res)
    right := dfs(root.Right,res)
    a := root.Val + max(0,left) + max(0,right) 
    b := root.Val + max(0,max(left,right))
    *res = max(*res,max(a,b))
    return b
}
func max(a,b int)int{
    if a > b{
        return a
    }else{
        return b
    }
}
```