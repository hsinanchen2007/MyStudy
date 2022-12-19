### 解题思路
非递归 逆向中序遍历

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
func kthLargest(root *TreeNode, k int) int {
    var stack [](*TreeNode)
    node := root

    for len(stack)!=0||node!=nil {
        if node != nil {
            stack = append(stack, node)
            node = node.Right
        }else {
            node = stack[len(stack)-1]
            k-- //遍历点
            if k == 0 {
                break
            }//endif
            stack = stack[:len(stack)-1]
            node = node.Left
        }//endif
    }//endfor

    return node.Val
}
```