### 本题求二叉树直径，所谓二叉树的直径，通俗理解就是把二叉树拉直了，最大的宽度
## NOTICE:经过根节点的直径不一定最大，不信你展开看看
### 直径等于左树高加右树高

```
func diameterOfBinaryTree(root *TreeNode) int {
    if root==nil{
        return 0
    }
    max:=0
    height(root,&max)
    return max
}
//本质上是求二叉树的最高高度，加了一个max用来求直径
func height(root *TreeNode,max *int)int{
    if root==nil{
        return 0
    }
    //左树高
    l:=height(root.Left,max)
    //右树高
    r:=height(root.Right,max)
    //更新最大直径
    (*max)=int(math.Max(float64(*max),float64(l+r)))
    //返回树高
    return int(math.Max(float64(l),float64(r)))+1
}
```
