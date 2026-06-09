### 解题思路
此处撰写解题思路
通过一个辅助函数findPorQ
判断P 或者 Q 是在 node的左子树 还是右子树；
1. 如果P、Q在left，return left
2. P、Q在right, return right
3. 一个在left 一个在right, return root
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
        return findPorQ(root, p , q);
    }

    private TreeNode findPorQ(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) return root;
   
        TreeNode left = findPorQ(root.left, p, q);
        TreeNode right = findPorQ(root.right , p, q);

        if (left != null && right != null) return root;
        return left == null ? right : left;
    }
}
```