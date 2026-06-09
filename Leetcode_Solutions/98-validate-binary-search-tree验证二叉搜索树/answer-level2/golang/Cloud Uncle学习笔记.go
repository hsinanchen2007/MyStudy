1. 如果一颗二叉树是二叉搜索树的话，那么它的中序遍历就是升序遍历，并且每个节点的值都不会重复
```
func isValidBST(root *TreeNode) bool {
    //中序遍历
    res := inorderTraversal(root)
    resMap := make(map[int]int)
    //每个节点的值不会重复，若重复的话就直接返回false
    for index, elem := range res {
        if _, exist := resMap[elem]; exist {
            return false
        }
        resMap[elem] = index
    }
    //判断是否为升序
    if sort.IntsAreSorted(res) {
        return true
    }

    return false
}

func inorderTraversal(root *TreeNode) []int {
    res := []int{}

    if root == nil {
        return nil
    }

    res = append(res, inorderTraversal(root.Left)...)
    res = append(res, root.Val)
    res = append(res, inorderTraversal(root.Right)...)

    return res
}
```
2.左子树所有节点的值不能大于左界(根节点的值)，右子树所有节点的值不能小于右界(根节点的值)
```
func isValidBST(root *TreeNode) bool {
    if root == nil {
        return true
    }

    return isBST(root, math.MinInt64, math.MaxInt64)
}

func isBST(root *TreeNode, left, right int) bool {
    if root == nil {
        return true
    }

    if left >= root.Val || right <= root.Val {
        return false
    }

    return isBST(root.Left, left, root.Val) && isBST(root.Right, root.Val, right)
}
```
