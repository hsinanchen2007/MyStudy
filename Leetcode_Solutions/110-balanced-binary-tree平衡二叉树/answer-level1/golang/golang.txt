```
/*
   1.若左子树不平衡，肯定不平衡
   2.若右子树不平衡，肯定不平衡
   3.左子树和右子树的高度差超过1，则不平衡
*/

func isBalanced(root *TreeNode) bool {
    return process(root) >= 0
}
/*
    递归返回值需要返回信息：是否平衡，若平衡需要返回自己的高度
    返回值： -1，不平衡
            0 ，节点为null
            >0, 以head为根节点的高度
            也可以封装成一个类，属性包括isBalance和h，只不过没有这样简洁
 */
func process(root *TreeNode) int {
    if root == nil {
        return 0
    }
    l := process(root.Left)
    if l < 0 {
        return -1
    }
    r := process(root.Right)
    if r < 0 {
        return -1
    }
    if abs(l - r) > 1 {
        return -1
    }
    return max(l, r) + 1
}

func abs (x int) int {
    if x < 0 {
        return -x
    }
    return x
}
func max (x, y int) int {
    if x > y {
        return x
    }
    return y
}
```
