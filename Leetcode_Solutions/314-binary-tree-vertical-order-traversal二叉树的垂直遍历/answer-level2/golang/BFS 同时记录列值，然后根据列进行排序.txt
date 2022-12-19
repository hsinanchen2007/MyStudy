### 解题思路

最重要的一点是，遍历的时候，需要记录列号。最简单的处理是，根所在列为 0 ，它的左子树列号减一，右子树加一。遍历使用 BFS 或者 DFS 都可以，Go 的话还是推荐 BFS ，因为 DFS 的话需要记录同一列的深度，根据深度排序，但 Go 提供的 sort 不具有稳定性，实测会出现同一列元素排序后和答案不一致的情况，除非自己再实现一个稳定的排序，会多一些工作量。

### 代码

```golang
import "sort"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
*/

type NodeWithColumn struct {
    Column int
    Node *TreeNode
}

func verticalOrder(root *TreeNode) [][]int {
    answer := make([][]int, 0)
    if root != nil {
        m := make(map[int][]int, 0)
        verticalOrderBFS(root, &m)
        var keys []int
        for k := range m {
            keys = append(keys, k)
        }
        sort.Ints(keys)
        for _, k := range keys {
           answer = append(answer, m[k])
        }
    }
    return answer
}

func verticalOrderBFS(root *TreeNode, m *map[int][]int) {
    var nodes []NodeWithColumn
    nodes = append(nodes, NodeWithColumn {
        Column: 0,
        Node: root,
    })
    for len(nodes) > 0 {
        node := nodes[0]
        nodes = nodes[1:]
        mv := *m
        mv[node.Column] = append(mv[node.Column], node.Node.Val)
        if node.Node.Left != nil {
            nodes = append(nodes, NodeWithColumn{
                Column: node.Column - 1,
                Node: node.Node.Left,
            })
        }
        if node.Node.Right != nil {
            nodes = append(nodes, NodeWithColumn{
                Column: node.Column + 1,
                Node: node.Node.Right,
            })
        }
    }
}
```