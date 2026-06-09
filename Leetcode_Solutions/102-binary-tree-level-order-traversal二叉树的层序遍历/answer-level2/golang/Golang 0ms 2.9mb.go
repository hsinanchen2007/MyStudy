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
func levelOrder(root *TreeNode) [][]int {
    result := make([][]int, 0)
    if root == nil {
        return result
    }
    curLevel := []*TreeNode{root}
    for len(curLevel) > 0 {
        item := make([]int, 0)
        nextLevel := make([]*TreeNode, 0)
        for _, n := range curLevel {
            if n != nil {
                item = append(item, n.Val)
                if n.Left != nil {
                    nextLevel = append(nextLevel, n.Left)
                }
                if n.Right != nil {
                    nextLevel = append(nextLevel, n.Right)
                }
            }
        }
        result = append(result, item)
        curLevel = nextLevel
    }
    return result
}
```