### 解题思路
层序遍历，奇数层反转结果

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
func zigzagLevelOrder(root *TreeNode) [][]int {
    if root == nil {
        return nil
    }
    var res = [][]int{}
    // 当前队列
    var queue = []*TreeNode{root}
    // 下一层队列
    var next = []*TreeNode{}
    // 当前层缓存，奇数层需要反转
    var cur = []int{}
    level := 0
    for len(queue) > 0 {
        node := queue[0]
        queue = queue[1:]
        if node.Left != nil {
            next = append(next, node.Left)
        }
        if node.Right != nil {
            next = append(next, node.Right)
        }
        cur = append(cur, node.Val)
        // 当前层遍历完成
        if len(queue) == 0 {
            queue = next
            next = []*TreeNode{}
            var tmp = make([]int, len(cur))
            copy(tmp, cur)
            if level % 2 != 0 {
                // 反转tmp
                i := 0
                j := len(tmp) - 1
                for i < j {
                    tmp[i], tmp[j] = tmp[j], tmp[i]
                    i++
                    j--
                }
            }
            res = append(res, tmp)
            cur = cur[0:0]
            level++
        }
    }
    return res
}
```