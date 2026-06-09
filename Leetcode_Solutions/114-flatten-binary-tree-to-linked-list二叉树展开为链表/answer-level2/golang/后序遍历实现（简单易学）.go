## 提供一个后序遍历的思路
```
//后序遍历法
func flatten(root *TreeNode)  {
    if root==nil{
        return
    }
    var pre *TreeNode
    //使用2重指针
    dfs(root,&pre)
}
func dfs(root *TreeNode,pre **TreeNode){
    if root==nil{
        return
    }
    //逆后序遍历
    dfs(root.Right,pre)
    dfs(root.Left,pre)
    root.Right=(*pre)
    root.Left=nil
    (*pre)=root
}
```
## 解释
先序遍历为1-2-3-4-5-6
如果按照先序遍历执行，1的左孩子为nil，右孩子为2，但是5就没了
因此，我们可以倒过来想，逆序执行，逆后序遍历：6-5-4-3-2-1
这样就不会盖掉前面的