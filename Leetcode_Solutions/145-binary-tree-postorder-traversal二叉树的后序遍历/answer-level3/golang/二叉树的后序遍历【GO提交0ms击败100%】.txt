### 解题思路

![image.png](https://pic.leetcode-cn.com/ca56f0a5258cb1f97dbe08112ce5aa4045b47bfbbb0d6877564e39d9d7f98908-image.png)

循环解题的思路来自二叉树的前序遍历，设结果链表的左侧为头部，则
- 考虑到前序遍历时结果链表的插入 顺序为 1根 -> 2左 -> 3右
- 如果修改为插入到结果链表尾部   顺序为 3右 -> 2左 -> 1根
- 如果再修改为先遍历右子树      顺序为 3左 -> 2右 -> 1根

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
    var result []int
    // recursion(root, &result)
    cycle(root, &result)
    
    return result
}

func recursion(node *TreeNode, result *[]int) {
    if node== nil {
        return
    }
    recursion(node.Left, result)
    recursion(node.Right, result)
    *result = append(*result, node.Val)
}

func cycle(node *TreeNode, result *[]int) {
    stack := list.New()
    iter := node
    for iter != nil || stack.Len() != 0 {
        for iter != nil {
            *result = append([]int{iter.Val}, *result...)
            stack.PushBack(iter)
            iter = iter.Right
        }
        iter = stack.Remove(stack.Back()).(*TreeNode)
        iter = iter.Left
    }
}
```