### 解题思路
这题思路不算难，首先分别在左子树和右子树中查找树节点p和q，注意到如果子树中不存在p和q则返回null，如果存在则返回公共祖先或p或q。
如果左右子树都返回null，则考虑当前节点是否为p或q，如果是则返回当前节点。
如果在左右子树中的查找都返回了非null的值，说明在左右子树中查找到了p或q，则可以返回当前节点作为最近公共祖先。
如果以上情况都不符合，则返回左右子树中查找的非null值。

### 有效性
不失一般性，假设p和q分别在左子树和右子树中，则在左右子树的查找不会返回空，则当前节点为最近公共祖先。
假设p和q都在左子树中，则右子树的查找必定返回空，则左子树查找的返回值为最近公共祖先。
假设p和q都不在左子树和右子树中，而当前节点为p或q，则返回当前节点，否则返回null。

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
        if(root == null)return null;
        TreeNode tmpLeft = lowestCommonAncestor(root.left, p, q);
        TreeNode tmpRight = lowestCommonAncestor(root.right, p, q);
        if(tmpLeft == null && tmpRight == null
            && root != p && root != q)return null;
        if(root == p || root == q)return root;
        if(tmpLeft != null && tmpRight != null)return root;
        return tmpLeft == null ? tmpRight : tmpLeft;
    }
}

```