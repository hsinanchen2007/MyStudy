常规二叉树递归
```go
func helper(root *TreeNode, sum int) int {
    if root == nil {
        return 0
    }
    if root.Left == nil && root.Right == nil {
        return root.Val + sum
    }
    return helper(root.Left, sum+root.Val) + helper(root.Right, sum+root.Val)
}
```

改造一下
```go
func pathSum(nums []int) int {
    tree := make([]int, 16)
    for i := range tree {
        tree[i] = -1
    }
    for i := range nums {
        pos, dep := nums[i]/10%10-1, nums[i]/100%10-1
        tree[1<<dep-1+pos] = nums[i] % 10 // 2^2 是异或……
    }
    return helper(tree, 0, 0)
}

func helper(tree []int, root, sum int) int {
    if tree[root] == -1 {
        return 0
    }
    if root >= 7 || tree[2*root+1] == -1 && tree[2*root+2] == -1 {  // 最后一层或者叶节点直接返回
        return tree[root] + sum
    }
    return helper(tree, 2*root+1, sum+tree[root]) + helper(tree, 2*root+2, sum+tree[root])
}
```