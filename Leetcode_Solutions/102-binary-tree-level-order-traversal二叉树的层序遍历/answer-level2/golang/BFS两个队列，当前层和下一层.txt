### 解题思路
用两个队列，分别记录当前层和下一层

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
func levelOrder(root *TreeNode) [][]int {
    if root == nil {
        return nil
    }
    var res [][]int
    // 队列
    var queue, next = []*TreeNode{root}, []*TreeNode{}
    // 当前层缓存
    var curr = []int{}
    for len(queue) != 0 {
        node := queue[0]
        curr = append(curr, node.Val)
        // 队列弹出
        queue = queue[1:]
        // 放到下一层
        if node.Left != nil {
            next = append(next, node.Left)
        }
        if node.Right != nil {
            next = append(next, node.Right)
        }

        // 当前层遍历完成
        if len(queue) == 0 {
            var ret = make([]int, len(curr))
            copy(ret, curr)
            res = append(res, ret)
            queue = next
            next = []*TreeNode{}
            curr = curr[0:0]
        }
    }
    return res
}
```