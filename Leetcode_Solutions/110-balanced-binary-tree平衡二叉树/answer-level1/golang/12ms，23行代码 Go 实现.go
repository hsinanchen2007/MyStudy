
![image.png](https://pic.leetcode-cn.com/68db6647cb60c586bb199cd551a518b31a31cf0ab201c4497b8603f0acb3ddfc-image.png)

同时返回当前树的深度和是否为平衡二叉树，一遍递归得到结果。

代码
```
func Abs(x int) int {   // 绝对值函数
    if x<0 {
        return -x
    }
    return x
}
func Balanced(root *TreeNode) (int, bool) { // 返回参数：当前树的深度，是否是平衡二叉树
    if root == nil {
        return 0, true
    }
    ld, lf := Balanced(root.Left)
    rd, rf := Balanced(root.Right)
    depth := ld         // 当前树深度
    if rd > depth {
        depth = rd
    }
    depth++
    return depth, Abs(ld-rd)<=1 && lf && rf     // 当前树是平衡二叉树 && 左右子树都是平衡二叉树
}
func isBalanced(root *TreeNode) bool {
    _,result := Balanced(root)
    return result
}
```