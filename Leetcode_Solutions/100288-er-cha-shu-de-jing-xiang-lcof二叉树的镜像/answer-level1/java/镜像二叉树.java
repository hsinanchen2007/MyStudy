### 解题思路  借助一个中间变量，来颠倒左右子树


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
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null) return null;
        TreeNode tempNode=root.left;
        root.left=mirrorTree(root.right);
        root.right=mirrorTree(tempNode);
        return root;
    }
}
```