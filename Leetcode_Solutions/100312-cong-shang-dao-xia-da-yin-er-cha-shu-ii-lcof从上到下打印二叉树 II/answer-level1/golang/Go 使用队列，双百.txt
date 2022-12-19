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

 type Node struct {
     Point *TreeNode
     Layer int
 }

func levelOrder(root *TreeNode) [][]int {
    if root==nil {
        return nil
    }
    res := make([][]int, 0)
    queue := []Node{Node{root, 1}}
    for len(queue)!=0 {
        node, layer := queue[0].Point, queue[0].Layer
        queue = queue[1:]
        if layer > len(res) {
            res = append(res, []int{})
        }
        res[layer-1] = append(res[layer-1], node.Val)
        if node.Left != nil {
            queue = append(queue, Node{node.Left, layer+1})
        }
        if node.Right != nil {
            queue = append(queue, Node{node.Right, layer+1})
        }
    }
    return res
}
```