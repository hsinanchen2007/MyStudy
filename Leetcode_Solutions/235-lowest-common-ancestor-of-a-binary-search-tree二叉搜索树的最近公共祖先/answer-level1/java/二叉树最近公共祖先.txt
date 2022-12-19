### 解题思路 1.了解二叉搜索树得特征，其节点没有相同值。2.判断盘p,q的大小值。


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
        if(root==null) return null;
        if((p.val<=root.val&&q.val>=root.val)||(p.val>=root.val&&q.val<=root.val)) return root;
        if(p.val<root.val&&q.val<root.val) return lowestCommonAncestor(root.left,p,q);
        else{
            return lowestCommonAncestor(root.right,p,q);
        }
    }
}
```