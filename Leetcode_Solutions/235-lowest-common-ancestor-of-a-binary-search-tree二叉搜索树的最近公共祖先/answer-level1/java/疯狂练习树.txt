### 解题思路
此处撰写解题思路
递归出口：如果其中的某个节点就是根节点则该根节点就是所求节点
递归操作：如果两个节点分布在根节点的左右两侧，则明显根节点就是所求节点，递归下去也是如此，如果均大于或者小于根节点则，遍历根节点的左子树以或者右子树

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
        if(p.val == root.val)
            return p;
        if(q.val == root.val)
            return q;
        if(p.val > root.val && q.val > root.val)
            return lowestCommonAncestor(root.right,p,q);
        else if(p.val < root.val && q.val < root.val)
            return lowestCommonAncestor(root.left,p,q);
        else
            return root;
    }
}
```