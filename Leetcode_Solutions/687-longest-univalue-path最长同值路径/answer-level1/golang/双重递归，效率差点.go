**解题思路**
依次计算出当前节点左右子树的最长路径，以及跟当前节点值相同的左右子树节点数。然后依次比较这几个数值取最大值，需要特别考虑的是情况是左右子树节点值跟当前节点相同时需要把左右节点数相加再转为变数再做比较。

**缺点**
进行了双重递归，最坏情况下树被扫了很多遍，效率比较低，只打败了55%的同类提交。
仅作解题参考。

**代码**
```
func longestUnivaluePath(root *TreeNode) int {
    var ans int
    if root == nil {
        return 0
    }

    left := longestUnivaluePath(root.Left)
    right := longestUnivaluePath(root.Right)
    ans1, ans2 := dfs(root, root.Val)
    //conver node number to the edge number
    ans1--
    ans2--

    //path cross left and right nodes
    if root.Left != nil && root.Left.Val == root.Val && root.Right != nil && root.Right.Val ==root.Val {        ans = ans1 + ans2
    } else {
        //compare left and right path length with the same value
        if ans < ans1 {
            ans = ans1
        }
        if ans < ans2 {
            ans = ans2
        }
    }

    //compare left and right subtree length with differ value
    if ans < left {
        ans = left
    }
    if ans < right {
        ans = right
    }

    return ans
}

func dfs(root *TreeNode, val int) (int, int) {
    if root == nil || root.Val != val {
        return 0, 0
    }

    left, right1 := dfs(root.Left, val)
    left1, right := dfs(root.Right, val)
    if left < right1 {
        left = right1
    }
    if left1 > right {
        right = left1
    }
    return 1 + left, 1 + right
}
```
