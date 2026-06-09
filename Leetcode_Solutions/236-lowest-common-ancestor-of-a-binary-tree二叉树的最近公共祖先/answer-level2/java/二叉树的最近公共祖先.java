### 解题思路
1. 如果当前节点是这两个点其中一个点本身或者null，应该返回当前点。否则，公共祖先在当前点的左孩子或者右孩子。按照这个思路递归。
2. 对于线索二叉树的最近祖先同样可以根据这个思路做，当前点值如果等于其中一个或者一大一小，则返回当前点。否则，如果当前点大于两个点，递归左侧，否则递归右侧。
3. 

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
        if(root == null || root == p || root == q) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if(left != null && right != null) return root;
        return left == null ? right : left;
    }
}
```