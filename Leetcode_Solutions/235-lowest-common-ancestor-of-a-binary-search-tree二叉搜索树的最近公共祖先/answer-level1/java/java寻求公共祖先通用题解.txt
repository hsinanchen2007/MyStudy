### 解题思路
求一个树的公共祖先通用思路：
如果左子树包含t1且右子树包含t2或右子树包含t2且左子树包含t1，返回root；
否则对左右子树递归函数。

要注意的是，若root等于t1或root等于t2，此时返回root
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
        if (p == null || q == null) {
            return null;
        }
        if (root.val == p.val || root.val == q.val) {
            return root;
        }
        if (findNode(root.left, p)) {
            if (findNode(root.right, q)) {
                return root;
            } else {
                return lowestCommonAncestor(root.left, p, q);
            }
        } else {
            if (findNode(root.left, q)) {
                return root;
            } else {
                return lowestCommonAncestor(root.right, p, q);
            }
            
        }
        
    }

    boolean findNode(TreeNode root, TreeNode node) {
        if (root == null || node == null) {
            return false;
        }
        if (root == node) {
            return true;
        }

        boolean found = findNode (root.left, node);
        if (!found) {
            found = findNode(root.right, node);
        }
        return found;
    }
}
```