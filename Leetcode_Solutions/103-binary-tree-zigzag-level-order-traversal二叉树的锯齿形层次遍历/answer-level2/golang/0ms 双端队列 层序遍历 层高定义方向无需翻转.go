### 解题思路
此处撰写解题思路

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
    var res [][]int
    if root == nil {
        return res
    }

    deque := list.New()
    deque.PushFront(root)
    h := 1

    for deque.Len()>0 {
        curLen := deque.Len()
        cur := make([]int,curLen)

        for i:=0; i<curLen; i++{
            node := deque.Remove(deque.Back()).(*TreeNode)
            curKey := curLen-i-1
            if h%2 != 0{
                curKey = i
            }

            cur[curKey] = node.Val
            if node.Left != nil {
                deque.PushFront(node.Left)
            }
            if node.Right != nil {
                deque.PushFront(node.Right)
            }
        }
        res = append(res,cur)
        h++
    }

    return res
}
```