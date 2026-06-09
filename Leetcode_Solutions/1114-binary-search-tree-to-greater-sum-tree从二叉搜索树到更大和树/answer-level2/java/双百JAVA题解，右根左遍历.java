右根左遍历二叉搜索树，依次累加计和。
```
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
    int total = 0;
    public TreeNode bstToGst(TreeNode root) {
        update(root);
        return root;
    }

    public void update(TreeNode node){
        if (null != node){
            update(node.right);
            total += node.val;
            node.val = total;
            update(node.left);
        }
    }
}
```


