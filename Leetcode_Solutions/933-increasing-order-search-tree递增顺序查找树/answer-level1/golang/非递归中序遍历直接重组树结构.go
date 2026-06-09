**解题思路**
运用栈中序遍历原有树，通过一个prev变量保持前一个节点，遍历过程中修改prev的左右孩子。

**参考代码**
```
func increasingBST(root *TreeNode) *TreeNode {
    var stack []*TreeNode
    var prev, newRoot *TreeNode

    p := root
    for p != nil {
        for p != nil {
            stack = append(stack, p)
            p = p.Left
        }

        for len(stack) > 0 {
            p = stack[len(stack)-1]
            stack = stack[:len(stack)-1]

            if newRoot == nil {
                newRoot = p
                prev = newRoot
            } else {
                prev.Left = nil
                prev.Right = p
                prev = p
            }

            p = p.Right
            if p != nil {
                break
            }
        }
    }

    return newRoot
}
```
