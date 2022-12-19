### 解题思路
跟二叉树的层次遍历类似 见[102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)
只是每一层只保留一个节点，右边覆盖左边的
时间复杂度O(N)
空间复杂度O(N)

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
var res []int
//二叉树层次遍历
func rightSideView(root *TreeNode) []int {
    res = []int{} //用了全局遍历，每次都要初始化

    levelOrder(root, 0) //从第0层开始

    return res
}

func levelOrder(root *TreeNode, level int) {
    if root == nil {
        return
    }
    if level >= len(res) {
        res = append(res, 0) //扩展一层
    }

    res[level] = root.Val //这里直接覆盖旧值，普通的层次遍历是res[level] = append(res[level],root.Val)
    levelOrder(root.Left, level+1)
    levelOrder(root.Right, level+1)

}


```