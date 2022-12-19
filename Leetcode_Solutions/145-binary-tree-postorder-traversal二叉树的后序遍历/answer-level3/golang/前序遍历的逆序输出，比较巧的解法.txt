### 解题思路
前序遍历的逆序输出，比较巧的解法

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
    // 后续遍历非递归，用先序遍历然后做逆序输出
    var res = []int{}
    var stack = []*TreeNode{root}
    for len(stack) > 0 {
        // 栈顶
        node := stack[len(stack) - 1]
        // 加到输出列表
        res = append(res, node.Val)
        // 弹出
        stack = stack[:len(stack) - 1]
        // 推入
        if node.Left != nil {
            stack = append(stack, node.Left)
        }
        if node.Right != nil {
            stack = append(stack, node.Right)
        }
    }
    if len(res) > 1 {
        // 逆序输出列表
        i := 0
        j := len(res) - 1
        for i < j {
            res[i], res[j] = res[j], res[i]
            i++
            j--
        }
    }
    return res
}
```