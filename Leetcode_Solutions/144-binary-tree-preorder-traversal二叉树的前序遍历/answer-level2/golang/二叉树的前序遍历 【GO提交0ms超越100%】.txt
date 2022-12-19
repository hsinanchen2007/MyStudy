### 解题思路

![image.png](https://pic.leetcode-cn.com/b8b9c39839386b256385e5d7e193861a184c6e58c80f136c10dfdff742bef68f-image.png)

经典数据结构基础题
1. 递归
2. 循环使用栈

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
func preorderTraversal(root *TreeNode) []int {
    var result []int
    // recursion(root, &result)
    cycle(root, &result)
    return result
}

// recursion
func recursion(node *TreeNode, result *[]int) {
    if node == nil {
        return
    }
    *result = append(*result, node.Val)
    recursion(node.Left, result)
    recursion(node.Right, result)
}

// cycle
func cycle(node *TreeNode, result *[]int) {
    if node == nil {
        return
    }
    stack := list.New()
    iter := node
    for iter != nil || stack.Len() != 0 {
        for iter != nil {
            *result = append(*result, iter.Val)
            stack.PushBack(iter)
            iter = iter.Left
        }
        iter = stack.Remove(stack.Back()).(*TreeNode)
        iter = iter.Right
    }
    
}
```