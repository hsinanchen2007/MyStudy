![image.png](https://pic.leetcode-cn.com/b6afd24d2ca72bde41937547ce1b823d043cac12b82140d813b24e1d508b6795-image.png)

首先 p.Val 有可能大于 q.Val，所以先判断调换位置

然后我们可以观察一下这道题的规律 ，因为是排序二叉树，所以一定满足左节点<=当前节点<=右节点。

![](https://pic.leetcode-cn.com/c6a06291ae5836ac71b03a5dbf99493d9adea3545fed4cbb47b7dc1af8712d06-file_1558786008010)

最后观察规律，可以发现，如果满足 **p.Val <= 当前节点.Val <= q.Val**，那么说明该节点就是 p 和 q 的最近公共祖先，返回当前节点的地址。如果不符合，就根据 p 和 q 的值判断去左子树找还是去右子树找。
```
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if p.Val > q.Val {
        p,q = q,p
    }
    if root == nil || p.Val<=root.Val && root.Val<=q.Val {
        return root
    } else if q.Val<=root.Val {
        return lowestCommonAncestor(root.Left,p,q)
    } else {
        return lowestCommonAncestor(root.Right,p,q)
    }
}
```