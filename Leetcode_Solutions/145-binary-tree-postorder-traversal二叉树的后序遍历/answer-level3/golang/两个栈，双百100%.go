### 解题思路
利用两个栈，一个负责先序遍历，一个负责存后序顺序

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
func postorderTraversal(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    // 方法二：用两个栈，第一个负责压入栈，弹出后把当前节点压入另一个栈，然后把左右孩子压入第一个栈
    var res = []int{}
    var stack1 = []*TreeNode{root}
    var stack2 = []*TreeNode{}
    for len(stack1) != 0 {
        // 弹出
        node := stack1[len(stack1) - 1]
        stack1 = stack1[:len(stack1) - 1]
        // 左孩子先入栈
        if node.Left != nil {
            stack1 = append(stack1, node.Left)
        }
        // 右孩子后入栈
        if node.Right != nil {
            stack1 = append(stack1, node.Right)
        }
        // 当前节点入另一个栈
        stack2 = append(stack2, node)
    }
    // 根据栈stack2弹出顺序输出
    for len(stack2) != 0 {
        node := stack2[len(stack2) - 1]
        res = append(res, node.Val)
        stack2 = stack2[:len(stack2) - 1]
    }
    return res
}
```