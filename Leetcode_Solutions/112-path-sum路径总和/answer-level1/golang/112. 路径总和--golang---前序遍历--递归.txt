### 解题思路

利用递归的前序遍历，找到从根节点到各个叶子节点的路径上的总和是否符合要求


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

func hasPathSum(root *TreeNode, sum int) bool {

    if root == nil {
        return false
    }

    return Run(0,root,sum)
}

func Run(t int,root *TreeNode,sum int) bool {
    res := false
    if root.Left == nil && root.Right == nil {  //叶子节点
        t += root.Val
        if t == sum {
            return true
        }
        return false
    }

    t += root.Val
    if root.Left != nil {   //已经没有左子树
        res = Run(t,root.Left,sum)
        if res {
            return res
        }
    }
    if root.Right != nil {  //已经没有右子树
        res = Run(t,root.Right,sum)
        if res {
            return res
        }
    }
    return res
}


```