### 解题思路
BFS遍历即可

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
func levelOrder(root *TreeNode) []int {
    if root == nil {
        return []int{}
    }
    var nodeList []*TreeNode = make([]*TreeNode,0)
    nodeList = append(nodeList, root)
    res := make([]int,0)
    for len(nodeList) != 0 {

        res = append(res, nodeList[0].Val)
        if nodeList[0].Left != nil {
             nodeList = append(nodeList, nodeList[0].Left)
        }
        if nodeList[0].Right != nil {
             nodeList = append(nodeList, nodeList[0].Right)
        }
        nodeList = nodeList[1:]
    }
    return res
}
```