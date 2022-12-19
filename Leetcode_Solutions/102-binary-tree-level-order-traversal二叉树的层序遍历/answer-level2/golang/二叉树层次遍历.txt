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
    if root == nil {
        return nil
    }
    var result = [][]int{}
    //用来记录当前层的值
    var levelVals = []int{}
    //用来记录当前层和下一层的节点列表
    var cur, next = []*TreeNode{root}, []*TreeNode{}
    for len(cur) != 0 {
        node := cur[0]
        cur = cur[1:]
        levelVals = append(levelVals, node.Val)
        if node.Left != nil {
            next = append(next, node.Left)
        }
        if node.Right != nil {
            next = append(next, node.Right)
        }
        //当前层已经遍历完，需要将当前层的所有值levelVals追加到结果集result里面
        if len(cur) == 0 {
            cur = next
            next = []*TreeNode{}
            tmp := make([]int, len(levelVals))
            copy(tmp, levelVals)
            //注意，需要重置levelVals来记录每一层的节点的值.
            levelVals = []int{}
            result = append(result, tmp)
        }
    }
    return result
}
```