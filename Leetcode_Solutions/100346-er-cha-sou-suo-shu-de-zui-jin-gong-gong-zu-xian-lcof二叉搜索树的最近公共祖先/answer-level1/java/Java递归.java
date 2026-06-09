### 解题思路
此处撰写解题思路

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
        if (root == null || p == null || q == null){
            return null;
        }
        if (root.val == p.val || root.val == q.val) return root;
        if ((root.val - p.val)*(root.val - q.val) < 0){
            //两个节点分别在BST树的两侧，公共节点就是根节点
            return root;
        }else{
            //两个节点在BST树的同一侧
            TreeNode newNode = root.val > p.val ? root.left:root.right;
            return lowestCommonAncestor(newNode,p,q);
        }
    }
}
```