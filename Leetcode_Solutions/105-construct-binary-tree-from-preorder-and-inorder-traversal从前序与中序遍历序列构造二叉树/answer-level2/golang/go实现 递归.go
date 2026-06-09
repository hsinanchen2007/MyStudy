func buildTree(preorder []int, inorder []int) *TreeNode {
      if len(preorder) == 0 || len(inorder) == 0{
        return nil
    }
    var index int
    root := &TreeNode{Val:preorder[0]}
    for i := range inorder{
        if inorder[i] == preorder[0]{
            index = i
            break
        }
    }
    root.Left = buildTree(preorder[1:index+1],inorder[:index])
    root.Right = buildTree(preorder[index+1:],inorder[index+1:])
    return root


}
/*
构建左右子树的时候为什么preorder以index+1做分割？
答案:
我们在 inorder 中找到 index 为根节点的下标
由于中序遍历特性，index 左侧都为左子树节点，所以左子树的节点有 index 个
那么同样的，由于前序遍历的特性，preorder 第一个元素（根节点）后跟着的就是它的左子树节点，一共有 index 个，所以切了 [1:index+1] 出来
*/