
![image.png](https://pic.leetcode-cn.com/95613ca5ce7c4bbe96f9aed8a5bd8bd3efcdf8909196e1417256fd62dfad1670-image.png)


```
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if root == p || root == q || root == nil {  // 找到了一个节点，返回那个节点，或者找到了叶子节点，直接返回
        return root
    }
    l := lowestCommonAncestor(root.Left,p,q)  // 如果该子树下包含要找的节点，那么返回该节点地址，否则返回 nil
    r := lowestCommonAncestor(root.Right,p,q)
    if l!=nil && r!=nil {  
        return root
    } else if l != nil { 
        return l
    } else if r != nil {
        return r
    }
    return nil  
}
```