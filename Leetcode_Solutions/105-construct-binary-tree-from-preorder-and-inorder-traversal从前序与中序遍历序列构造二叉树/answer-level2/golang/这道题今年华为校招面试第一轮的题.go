思路其实和平时复现二叉树的类似。
通过preorder 的数组找出数组的根
然后通过定位根在inorder中的index来确定left subtree 和 right subtree。

注意里面一些边界条件的判断，不要超出数组长度

这到题是当是一开始没状态，一下没想起来，不过面试官还是很nice的稍加引导，最后也做出来了
结果最后一轮还是挂了 -_-!

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
    var rootVal = preorder[0]
    var inorderIndex = findIndex(inorder, rootVal)
    var leftInorderSet, rightInorderSet = make([]int,0), make([]int,0)
    var leftPreorderSet, rightPreorderSet = make([]int,0), make([]int,0)
    if inorderIndex > 0 {
        leftInorderSet = inorder[0:inorderIndex]
        leftPreorderSet = preorder[1:1+len(leftInorderSet)]
    } 
    if inorderIndex + 1 < len(inorder) && inorderIndex >= 0 {
        rightInorderSet = inorder[inorderIndex + 1 :]
        rightPreorderSet = preorder[len(leftInorderSet) + 1 :]
    }
    var root = &TreeNode{
        Val: rootVal,
    }
    root.Left = buildTree(leftPreorderSet, leftInorderSet)
    root.Right = buildTree(rightPreorderSet, rightInorderSet)
    return root
}


func findIndex(arr []int, value int) int {
    for index, val := range arr {
        if val == value {
            return index
        }
    }
    return -1
}
```