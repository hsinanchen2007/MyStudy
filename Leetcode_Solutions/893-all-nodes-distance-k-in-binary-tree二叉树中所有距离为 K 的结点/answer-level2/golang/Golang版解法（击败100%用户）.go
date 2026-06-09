![image.png](https://pic.leetcode-cn.com/89b266e875d403ea0bf52413c87d83883f925a824bde035c65f91ec0489e0419-image.png)

```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func distanceK(root *TreeNode, target *TreeNode, K int) []int {
    res := make([]int, 0)
    helper(root, target, &res, K)
    return res
}

func helper(root *TreeNode, target *TreeNode, res *[]int,  k int) int {
    if root == nil {
        return -1
    }

    if root == target {
        findInSubTree(target, res, k)
        return k
    }

    lk := helper(root.Left, target, res, k)
    rk := helper(root.Right, target, res, k)
    if lk <0 && rk <0 {
        return -1
    }

    if lk <0  { // rk>=0: found in root.Right
        if rk == 1 {
            *res = append(*res, root.Val)
        } else { // rk >1
            findInSubTree(root.Left, res, rk-2)
        }
        return rk-1
    }

    // found in root.Left
    if lk == 1 {
        *res = append(*res, root.Val)
    } else {
        findInSubTree(root.Right, res, lk-2)
    }
    return lk-1
}

func findInSubTree(target *TreeNode, res *[]int, k int) {
    if target == nil {
        return
    }

    if k == 0 {
        *res = append(*res, target.Val)
        return
    }

    findInSubTree(target.Left, res, k-1)
    findInSubTree(target.Right, res, k-1)
}
```