### 解题思路
根据官方题解写出

### 代码

```golang
func sumEvenGrandparent(root *TreeNode) int {
    return dfs(1,1,root)
}

func dfs(gp_val, p_val int, node *TreeNode) (res int) {
    // 递归限定条件
    if node == nil{
        return
    }
    // 如果祖父节点的值为偶数，则结果加上当前节点的值
    if gp_val % 2 == 0{
        res += node.Val
    }
    // 递归左右子节点
    res += dfs(p_val, node.Val, node.Left)
    res += dfs(p_val, node.Val, node.Right)
    return
}
```

### 运行结果
![image.png](https://pic.leetcode-cn.com/994a2ffe294543c56bbadc9e2d0a831b42926955325021c9db9b069005d26979-image.png)
