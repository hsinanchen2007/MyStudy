### 解题思路
采用双队列处理，一个父队列，一个子队列。
每层求和时，创建一个新的队列来存子节点。

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

func maxLevelSum(root *TreeNode) int {
    if root == nil {
        return 0
    }
    queue := []*TreeNode{root}
    sum := 0
    maxSum := 0
    level := 0
    res := level
    for len(queue)>0 {
        // 记录每一层
        level++
        // 先创建一个队列来存子节点，并重置为0，来重新开始
        newQueue := make([]*TreeNode, 0)
        // 计算每一层
        for _, v := range queue {
            sum += v.Val
            if v.Left != nil {
                newQueue = append(newQueue, v.Left)
            }
            if v.Right != nil {
                newQueue = append(newQueue, v.Right)
            }
        }
        // 保留当前节点和最大值的层
        if maxSum < sum {
            maxSum = sum
            res = level
        }
        // 清0，为下次计算做准备
        sum = 0
        // 指向子队列
        queue = newQueue
    }
    return res
}
```