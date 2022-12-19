### 解题思路
本题中只需考虑搜素二叉树的性质：搜索二叉树中，一个节点一定小于它的父亲节点，且大于左孩子小于右孩子

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(p.val<root.val&&q.val<root.val)
        return lowestCommonAncestor(root.left,p,q);
        if(p.val>root.val&&q.val>root.val)
        return lowestCommonAncestor(root.right,p,q);
        return root;
    }
}
```