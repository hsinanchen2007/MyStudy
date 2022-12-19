### 解题思路
此处撰写解题思路
搜索二叉树的最近公共祖先，左子树小于右子树的值
递归出口： 如果root为空则直接返回
递归操作： 如果给定的p和q的值都比root的值大说明要找的祖先在root的左侧，如果都比root的值小说明在优右侧，如果不满足同时小于或者大于，则此时的根节点就为公共祖先
返回值： 返回祖先root
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
        if(root == null)
            return root;
        if(root.val > p.val && root.val > q.val)
            return lowestCommonAncestor(root.left,p,q);
        if(root.val < p.val && root.val < q.val)
            return lowestCommonAncestor(root.right,p,q);
        return root;
    }
}
```