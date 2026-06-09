### 运行结果
执行结果: 通过
执行用时: 0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗: 2.6 MB, 在所有 Go 提交中击败了54.76%的用户


### 解题思路
用一个队列`queue`保存下一层次的所有节点，变量`order`控制子节点加入队列的顺序。
order 为true: 先加左子节点，再加右子节点；
每次queue中的子节点正好是下次遍历的反序，所以每次从queue的后面开始倒序遍历。

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
    ret := [][]int{}
    queue := []*TreeNode{}
    order := true
    queue = append(queue, root)
    for len(queue) > 0 {
        currentLevelNode := []int{}
        newQueue := []*TreeNode{}
        if order {
            for i := len(queue) - 1; i >=0; i -- {
                if queue[i] == nil {
                    continue
                }
                currentLevelNode = append(currentLevelNode, queue[i].Val)
                newQueue = append(newQueue, queue[i].Left)
                newQueue = append(newQueue, queue[i].Right)
            }
        } else {
            for i := len(queue) - 1; i >=0; i -- {
                if queue[i] == nil {
                    continue
                }
                currentLevelNode = append(currentLevelNode, queue[i].Val)
                newQueue = append(newQueue, queue[i].Right)
                newQueue = append(newQueue, queue[i].Left)
            }
        }
        if len(currentLevelNode) > 0 {
            ret = append(ret, currentLevelNode)
        } 
        queue = newQueue
        order = !order
    }
    return ret
}
```