### 解题思路
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2 MB, 在所有 Go 提交中击败了100.00%的用户

### 代码

```golang

func preorderTraversal(root *TreeNode) []int {
    r := []int{}
    preT(root,&r)
    return r
}


func preT(root *TreeNode,x *([]int)){
    if root != nil {
        *x = append(*x,root.Val)
        preT(root.Left,x)
        preT(root.Right,x)
    }
}
```