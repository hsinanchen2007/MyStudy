### 解题思路
利用切片模拟stack，
将根节点入栈
每次从切片尾部取出一个节点（出栈），
1. 将该节点的值追加到另外一个切片里面（根节点先序遍历）
2. 将节点的右孩子入栈
3. 再将左孩子入栈

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
func preorderTraversal(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    results := make([]int, 0)
    nodes := make([]*TreeNode, 0, 1)
    nodes = append(nodes, root)
    for len(nodes) != 0 {
        node := nodes[len(nodes)-1]
        nodes = nodes[:len(nodes)-1]
        results = append(results, node.Val)
        if node.Right != nil {
            nodes = append(nodes, node.Right)
        }
        if node.Left != nil {
            nodes = append(nodes, node.Left)
        }
    }
    return results
}
```