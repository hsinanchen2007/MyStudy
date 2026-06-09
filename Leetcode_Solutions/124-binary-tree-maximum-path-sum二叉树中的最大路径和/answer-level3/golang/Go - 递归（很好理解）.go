8ms-6.7MB
```
func maxPathSum(root *TreeNode) int {
    var res = -1<<30
    maxSum(root,&res)
    return res
}
//maxValue记录了每个结点的最大值
func maxSum(root *TreeNode,maxValue *int)int{
    if root==nil{
        return 0
    }
    //求出每一个结点的最大路径和，必然是自己左节点的最大和或者右节点的最大和
    //
    left := maxSum(root.Left,maxValue)
    right := maxSum(root.Right,maxValue)
    //这里返回的是每一个结点到自己左右孩子的路径
    nodeSum := root.Val+max(max(0,left),max(0,right))
    //这里计算当前结点的最大路径和
    all := root.Val + max(0,left) + max(0,right)
    *maxValue = max(*maxValue,all)
    return nodeSum
}

func max(x,y int)int{
    if x > y {
        return x
    }
    return y
}
```
