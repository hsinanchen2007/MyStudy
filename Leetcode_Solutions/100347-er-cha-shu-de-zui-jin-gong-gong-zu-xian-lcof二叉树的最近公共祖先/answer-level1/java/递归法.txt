### 解题思路
通过遍历数组,统计左右子树中出现的pq的个数
如果左子树有pq中的一个,右子树有pq中的一个,则root节点为结果
如果左子树中有pq中的一个,root节点等于pq中的一个,则root节点为结果

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
    public TreeNode res;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        lowestCommonAncestorCore(root, p, q);
        return res;
    }

    public int lowestCommonAncestorCore(TreeNode root, TreeNode p, TreeNode q) {
        if (root != null) {
            int left = lowestCommonAncestorCore(root.left, p, q);
            int right = lowestCommonAncestorCore(root.right, p, q);
            if (left == 1 && right == 1) res = root;
            if (left + right == 1 && (root == p || root == q)) res = root;
            if (root == p || root == q) return left + right + 1;
            return left + right;
        } else return 0;
    }
}
```