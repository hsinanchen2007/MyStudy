### 解题思路
![image.png](https://pic.leetcode-cn.com/22744f4e3a09af62982f15e8ea3b0d0ee1405c994eaaff4e666a8b7d90fcf717-image.png)
口诀：左空则跳，右空则引，右有则消
Morris树.jpg
![image.png](https://pic.leetcode-cn.com/a0d2b12ba6c4f43ed68abaa2da058e01c476d12d03affc07e65e2f699dd43f2b-image.png)

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
        return []int{}
    }
    var (
        last = root
        result = []int{}
        helper func(root *TreeNode)
    )
    helper = func(root *TreeNode) {
        temp := []int{}
        for root != nil {
            temp = append(temp,root.Val)
            root = root.Right
        }
        for i := len(temp)-1; i >= 0; i-- {
            result =append(result,temp[i])
        }
    }
    for root != nil {
        if root.Left == nil {
            root = root.Right
        }else {
            var prev *TreeNode
            node := root.Left
            for node.Right != nil {
                prev = node
                node = node.Right
                if node == root {
                    prev.Right = nil
                    helper(root.Left)
                    break
                }
            }
            if node != root && node.Right == nil {
                node.Right = root
                root = root.Left
            }else {
                root = root.Right
            }
        }
    }
    helper(last)
    return result
}
```