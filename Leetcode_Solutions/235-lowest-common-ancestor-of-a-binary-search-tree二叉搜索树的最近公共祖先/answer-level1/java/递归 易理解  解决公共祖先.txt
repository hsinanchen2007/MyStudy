### 解题思路
递归
若 root的值在 p q之间 即p q 在root的两侧 则root为所求公共祖先
若 root的值大于 max(p.val,q.val) 所求公共祖先在root的左侧 ->递归求解 ；否则 所求公共祖先在root的右侧 ->递归求解



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
        int max = Math.max(p.val, q.val);
        int min = Math.min(p.val, q.val);
        if(root.val >= min && root.val <= max) return root;
        if(root.val > max) return lowestCommonAncestor(root.left, p, q);
        else return lowestCommonAncestor(root.right, p, q);
    }
}
```