func inorderTraversal(root *TreeNode) []int {
    stack := make([]*TreeNode, 0)
    res := make([]int, 0)
    for {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        if len(stack) == 0 {
            break
        }
        node := stack[len(stack) - 1]
        res = append(res, node.Val)
        stack = stack[:len(stack) - 1]
        if node.Right != nil {
            root = node.Right
        }
    }
    return res
}