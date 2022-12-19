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
func isValidBST(root *TreeNode) bool {
    if root == nil {
        return true
    }

    _,_, ret := subTreeValid(root)
    return ret
}

func subTreeValid(root *TreeNode) (int, int, bool) {
    // 最小值
    var minest = root.Val
    var maxest = root.Val
    if root.Left != nil {
        min, max, leftRet := subTreeValid(root.Left)
        if !leftRet {
            return minest, maxest, false
        }
        if max >= root.Val {
            return minest, max, false
        } 
        minest = min
    }
    if root.Right != nil {
        min, max, rightRet := subTreeValid(root.Right)
        if !rightRet {
            return minest, maxest, false
        }
        if min <= root.Val {
            return minest, maxest, false
        }
        maxest = max
    }
    return minest, maxest, true
}



```