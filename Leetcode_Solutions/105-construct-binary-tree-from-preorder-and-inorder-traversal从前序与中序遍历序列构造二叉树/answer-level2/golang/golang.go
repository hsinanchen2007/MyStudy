```
/**
    根据前序得到根节点，然后把中序分成两份，根据中序的左右两份的距离，回过头来再确定前序的距离
    为了O(1)得到前序的treenode在中序的位置，把中序放到map中
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
    inorderMap := make(map[int]int)
    for i, v := range inorder {
        inorderMap[v] = i
    }

    return process(inorderMap, 0, len(preorder) - 1, preorder, 0, len(preorder) - 1)
}

//在preorder和inorder的i...j范围构造树，返回头节点
func process(inorder map[int]int, ii, ij int, preorder []int, pi, pj int) *TreeNode{
    if pi > pj || ii > ij {//其实其中一对坐标合理， 另一对肯定也合理，因为是等长的
        return nil
    }
    //创建根节点
    v := preorder[pi]
    root := &TreeNode{Val: v}
    //得到根节点在中序的位置
    index := inorder[v]
    root.Left  = process(inorder, ii, index - 1, preorder, pi + 1, pi + index - ii)
    root.Right = process(inorder, index + 1, ij, preorder, pi + index - ii + 1, pj)
    return root
}

```
