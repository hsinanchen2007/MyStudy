
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 * 1. 从题目可知是一道二叉树相关问题,首先想到递归或栈结构
 * 2. 构建二叉树,二叉树具有递归结构性,自然想到使用递归来构建二叉树
 * 3. 如何构建递归子问题? 根据前序遍历可以快速底定位根的位置,中序遍历可以划分出左子树与右子树的元素集合
 * 4. 递归基是什么? 中序数组被划分为空,说明已经到达叶子节点返回nil即可
 * 5. 递归体如何实现? 搜索划分点 + 构建二叉树
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
        if len(inorder) == 0{
            return nil
        }
        idx := -1
        for i,v:=range inorder{
            if v == preorder[0]{
                idx = i
            }
        }
        root := &TreeNode{Val:preorder[0]}
        root.Left = buildTree(preorder[1:idx+1],inorder[:idx])
        root.Right = buildTree(preorder[idx+1:],inorder[idx+1:])
        return root
}
```