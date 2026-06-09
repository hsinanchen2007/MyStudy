### 解题思路
此处撰写解题思路
此处给定的函数类型是TreeNode，因此可以返回节点，不需要额外创建函数用于递归遍历；因为是求最近父节点，因此可以使用后续遍历
一： 递归出口，如果root==null 或者root的值等于p的值或者q的值，则应该返回root
二： 递归操作，遍历左子树，遍历右子树
三： 返回操作，如果left以及right都为null则返回root，如果left为null则返回right，right为空则返回left
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
        if(root == null || root.val == p.val || root.val == q.val)
            return root;
        TreeNode left = lowestCommonAncestor(root.left,p,q);
        TreeNode right = lowestCommonAncestor(root.right,p,q);
        if(left == null)
            return right;
        if(right == null)
            return left;
        return root;
    }
}
```