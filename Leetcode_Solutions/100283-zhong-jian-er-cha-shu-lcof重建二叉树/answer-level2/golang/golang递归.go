### 解题思路
inorderRootIndex 是中序遍历树根节点的位置
 同时这个索引也是左子树得长度
所以 1->inorderRootIndex+1 就是先序遍历左子树得长度
递归参数是先序左子树和中序左子树
    rootNode.Left = buildTree(preorder[1:inorderRootIndex+1], inorder[:inorderRootIndex])
递归参数是先序右子树和中序右子树
    rootNode.Right = buildTree(preorder[inorderRootIndex+1:], inorder[inorderRootIndex+1:])


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
    if len(preorder)==0 || len(inorder)==0 {
        return nil
    }

    inorderRootIndex := -1
    for k, v := range inorder{
        if preorder[0] == v {
            inorderRootIndex = k
            break
        }
    }
    
    rootNode := &TreeNode{
        Val: preorder[0],
    }

    // inorderRootIndex 是中序遍历树根节点的位置
    // 同时这个索引也是左子树得长度
    // 所以 1->inorderRootIndex+1 就是先序遍历左子树得长度
    //递归参数是先序左子树和中序左子树
    rootNode.Left = buildTree(preorder[1:inorderRootIndex+1], inorder[:inorderRootIndex])
    //递归参数是先序右子树和中序右子树
    rootNode.Right = buildTree(preorder[inorderRootIndex+1:], inorder[inorderRootIndex+1:])

    return rootNode


}
```