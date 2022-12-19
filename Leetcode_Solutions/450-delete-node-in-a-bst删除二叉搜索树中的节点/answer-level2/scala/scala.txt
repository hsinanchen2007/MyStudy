1. 查找key
2. 将左右子数合并，左子树挂到右子树的最左
3. 更新root，如果存在

``` scala []

object Solution {   
    type T = TreeNode    
    def find(nd:T, rt:T, x:Int):(T, T) = {
        if(nd == null) (null, null) else
        {
            if(nd.value > x) find(nd.left, nd, x)
            else if(nd.value == x) (nd, rt)
            else find(nd.right, nd, x)
        }
    }
    
    def merge(r1:T, r2:T):T = (r1, r2) match {
        case (null, _) => r2
        case (_, null) => r1
        case (_,_) => assignToLeftMost(r1,r2); r2
    }
    
    def assignToLeftMost(r1:T, r2:T):Unit = {
        if(r2.left == null) r2.left = r1 
        else assignToLeftMost(r1, r2.left)
    }
    
    def deleteNode(root: T, key: Int): T = find(root, null, key) match {
        case (null, _) => root
        case (node, null) => merge(node.left, node.right)
        case (node, parent) => 
        if(key < parent.value) parent.left = merge(node.left,node.right)
        else parent.right = merge(node.left, node.right)
        root
    }
}
```
