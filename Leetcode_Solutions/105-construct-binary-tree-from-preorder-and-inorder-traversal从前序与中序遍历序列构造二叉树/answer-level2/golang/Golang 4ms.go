### 运行结果
执行结果: 通过
执行用时: 4 ms, 在所有 Go 提交中击败了96.02%的用户
内存消耗: 3.9 MB, 在所有 Go 提交中击败了95.45%的用户

### 解题思路
前序遍历中第一个元素为root的值(假设为val)，在中序遍历中，0-idx(val)为左子树的元素，idx(val)+1-end为右子树元素。递归左子树和右子树即可。
递归时添加判断剪枝，运行用时可以从12ms缩减到4ms.

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
func buildTree(preorder []int, inorder []int) *TreeNode {
    if len(preorder) == 0 {
        return nil
    }
    root := &TreeNode{}
    root.Val = preorder[0]
    idx := 0
    for idx = 0; idx < len(inorder); idx ++ {
        if inorder[idx] == preorder[0] {
            break
        }
    }
    if idx > 0 {
        root.Left = buildTree(preorder[1:idx+1], inorder[0:idx])
    }
    if idx < len(preorder) - 1{
        root.Right = buildTree(preorder[idx+1:], inorder[idx+1:])
    }
    
    return root
}
```