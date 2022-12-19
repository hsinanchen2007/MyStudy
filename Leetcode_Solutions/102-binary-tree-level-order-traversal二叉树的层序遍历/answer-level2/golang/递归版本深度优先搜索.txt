
深度优先解此题，可以在每次访问到一个节点，把该节点所在层次的集合进行更新。和广度优先相比，是纵向和横向的对比。
解1，用slice传参，返回覆盖
```go
func levelOrder(root *TreeNode) [][]int {
    var res [][]int
    if root == nil{
        return res
    }    
    return dfs(root,0,res)
}

func dfs(node *TreeNode,level int, res [][]int) [][]int{
    if node == nil {
        return res
    }
    if len(res) <= level {
        res = append(res,[]int{})
    }
    res[level] = append(res[level],node.Val)
    res = dfs(node.Left,level+1,res)
    res = dfs(node.Right,level+1,res)
    return res

}
```

解2，用指针方式直接修改用于输出的二维slice (注意指针操作符优先级低于取下标操作符)
```go
func levelOrder(root *TreeNode) [][]int {
    var res [][]int
    if root == nil{
        return res
    }  
    dfs(root,0,&res)
    return res
}

func dfs(node *TreeNode,level int, pointer *[][]int){
    if node == nil {
        return 
    }
    if len(*pointer) <= level {
        *pointer = append(*pointer,[]int{})
    }
    (*pointer)[level] = append((*pointer)[level],node.Val)
    dfs(node.Left,level+1,pointer)
    dfs(node.Right,level+1,pointer)
}
```

