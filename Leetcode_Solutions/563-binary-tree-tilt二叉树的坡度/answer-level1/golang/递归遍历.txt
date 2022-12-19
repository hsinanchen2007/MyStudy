```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findTilt(root *TreeNode) int {
    ans := 0
    traverse(root,&ans)
    return ans
}

func traverse(root *TreeNode,ans *int)int{
    if root == nil{
        return 0
    }
    //Left 全部节点的值之和
    lv := traverse(root.Left,ans)
    //Right 全部节点的值之和
    rv := traverse(root.Right,ans)
    //计算节点坡度
    //累计到answer指针
    *ans += absSub(lv,rv)
    //return 节点的的Val值和
    return rv + lv + root.Val
}
//减法绝对值
func absSub(a,b int)int{
    if a > b {
        return a -b
    }
    return b-a
}
```