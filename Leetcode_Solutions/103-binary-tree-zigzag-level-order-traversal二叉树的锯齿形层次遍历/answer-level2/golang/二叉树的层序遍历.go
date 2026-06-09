### 解题思路
类似于二叉树的层序遍历，只不过需要在偶数层同时进行数组的反转（逆序将节点的值存储到数组里面）

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
    if root == nil {
        return nil
    }
    var result = make([][]int, 0, 1)
    var cur, next = []*TreeNode{root}, []*TreeNode{}
    //注意，数组tmp预先分配好长度，因为偶数层的时候需要逆序存储结果。后面再变更层次的时候重新分配，长度为当前层的节点的数量。
    var tmp = make([]int, 1)
    //level 用来记录当前的层次，从第一层开始计数，后面需要在变更层次的时候更新
    var level int = 1
    //用来记录每一层里面处理到第几个节点了
    var j int = 0
    for len(cur) > 0 {
        node := cur[0]
        cur = cur[1:]
        if node.Left != nil {
            next = append(next, node.Left)
        }
        if node.Right != nil {
            next = append(next, node.Right)
        }
        //奇数层顺序存储结果集
        if level & 1 == 1 {
            tmp[j] = node.Val
        } else {
            //偶数层逆序存储结果集
            tmp[len(tmp)-1-j] = node.Val
        }
        j++
        if len(cur) == 0 {
            result = append(result, tmp)
            cur = next
            next = []*TreeNode{}
            tmp = make([]int, len(cur))
            level++
            j = 0
        }
    }
    return result
}
```