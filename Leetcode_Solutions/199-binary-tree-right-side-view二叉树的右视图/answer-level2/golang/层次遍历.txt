### 解题思路
该题跟层次遍历思想一样，只不过结果集只需要最右边的元素

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
 // 层次遍历，获取每一次层最右边的元素，追加到结果集合中
func rightSideView(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    var result = []int{}
    var cur, next = []*TreeNode{root}, []*TreeNode{}

    for len(cur) != 0 {
        node := cur[0]
        cur = cur[1:]
        if node.Left != nil {
            next = append(next, node.Left)
        }
        if node.Right != nil {
            next = append(next, node.Right)
        }
        if len(cur) == 0 {
            result = append(result, node.Val)
            cur = next
            next = []*TreeNode{}
        }
    }
    return result
}
```