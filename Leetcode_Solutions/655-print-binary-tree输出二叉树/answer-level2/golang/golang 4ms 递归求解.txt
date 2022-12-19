重点在于：
 * 明确切片的宽度
因为空格都要算上其实就是对应满二叉树节点的个数；
而满二叉树的个数与该数的高度有关，故先求高度，2^h - 1即为宽度
```
//求深度根节点深度为1
func deep(root *TreeNode) int {
    if root == nil {
        return 0
    }
    return max(deep(root.Left)+1, deep(root.Right)+1)
}
```

* 构建二维切片，golang组建二维切片不好理解，好在可以确认二维切片的大小，不然使用起来还得考虑切片扩展地址改变不易作为参数的问题
//组建二维切片
    m := deep(root) //行数 
    n := int(math.Pow(float64(2), float64(m))) - 1 //列数
    var res [][]string
    for i := 0; i < m; i++{
        col := make([]string, n)
        res = append(res, col)
    }
    helper(root, 0, 0, n-1, res)
    return res
* 如何把结果写入二维切片里
画图分析，发现根节点在第一层中间，左子树在左边剩余位置的中间，右子树在剩余位置的中间，故记录深度，没深入一层，二分之
```
func helper(root *TreeNode, d, l, r int, res [][]string){
    if root == nil {
        return
    }
    mid := (l + r)/2
    res[d][mid] = strconv.Itoa(root.Val)
    helper(root.Left, d+1, l, mid-1, res)
    helper(root.Right, d+1, mid+1, r, res)
}
```