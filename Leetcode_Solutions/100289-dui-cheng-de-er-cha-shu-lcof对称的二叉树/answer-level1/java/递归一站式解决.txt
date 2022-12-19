
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
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root,root);
    }
    public boolean isMirror(TreeNode node1,TreeNode node2){
        //两个节点都为空,则对称
        if(node1 == null && node2 == null) return true;
        //有一个不为空，一个为空则不对称
        if(node1 == null || node2 == null) return false;
        return (node1.val == node2.val) && isMirror(node1.left,node2.right)
            && isMirror(node1.right,node2.left);
    }
}
```