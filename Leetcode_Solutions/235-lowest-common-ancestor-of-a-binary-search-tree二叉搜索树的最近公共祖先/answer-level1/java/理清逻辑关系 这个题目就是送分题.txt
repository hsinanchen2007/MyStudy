来我给你们捋捋

**总共就两种情况:**
1. p q 在根节点的一侧
    此时继续递归就好了, 同时大于root.val就递归右子树, 同时小于root.val就递归左子树
2. p q不在根节点的一侧
    此时最近的公共祖先就是root, 不明白? 继续捋
    p q不在根节点的一侧又分为两种情况:
    1. p q分布在root的两边, 显而易见公共祖先就是root
    2. 要么p=root 要么q=root 此时公共祖先还是root

```
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // p q 在root节点的一侧(同时大于或者同时小于root)
        if (p.val > root.val && q.val > root.val)
            return lowestCommonAncestor(root.right, p, q);
        else if (p.val < root.val && q.val < root.val)
            return lowestCommonAncestor(root.left, p, q);
        // p q 不同时在root节点的一侧
        else
            return root;    
    }
}
```
