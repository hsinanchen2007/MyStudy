### 解题思路
递归解法不难，类似二叉树遍历，稍作抽象即可。
关键是怎么实现非递归解法。

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
func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
    // 构造新节点，保存合并后的结果值
    resultNode := &TreeNode{}
    var t1Left *TreeNode
    var t2Left *TreeNode
    var t1Right *TreeNode
    var t2Right *TreeNode

    // 处理t1和t2
    if t1 == nil && t2 == nil {
        return nil
    } else if t1 != nil && t2 == nil {
        resultNode.Val = t1.Val
        t1Left = t1.Left
        t1Right = t1.Right
    } else if t1 == nil && t2 != nil {
        resultNode.Val = t2.Val
        t2Left = t2.Left
        t2Right = t2.Right
    } else {
        resultNode.Val = t1.Val + t2.Val
        t1Left = t1.Left
        t1Right = t1.Right
        t2Left = t2.Left
        t2Right = t2.Right
    }

    // 递归处理t1和t2的左子树
    resultNode.Left = mergeTrees(t1Left, t2Left)

    // 递归处理t1和t2的右子树
    resultNode.Right = mergeTrees(t1Right, t2Right)

    return resultNode
}
```