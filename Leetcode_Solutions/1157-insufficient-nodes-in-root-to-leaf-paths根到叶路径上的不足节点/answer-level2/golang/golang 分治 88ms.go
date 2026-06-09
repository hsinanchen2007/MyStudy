从根结点出发，把值累加直到叶子节点。
如果 sum + root.Val < limit, 满足条件，直接把叶子节点置为nil，并返回false

分别判断左右两边的值，
如果一个跟的两个子节点都是false，那么经过这个根的sum都小于limit，把该节点置为nil


```
func sufficientSubset(root *TreeNode, limit int) *TreeNode {
    if !sfs(root, limit, 0) {
        return nil
    }
    return root
}

func sfs(root *TreeNode, limit, sum int) bool {
    if root == nil {
        return false
    }
    if root.Left == nil && root.Right == nil {
        sum += root.Val
        if sum < limit {
            root = nil
            return false
        }
        return true
    }
    l := sfs(root.Left, limit, sum + root.Val)
    if !l {
        root.Left = nil
    }
    r := sfs(root.Right, limit, sum + root.Val)
    if !r {
        root.Right = nil
    }
    if !l && !r {
        root = nil
    }
    return 
```