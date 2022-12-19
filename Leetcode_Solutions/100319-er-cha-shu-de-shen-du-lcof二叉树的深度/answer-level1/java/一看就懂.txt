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
    public int maxDepth(TreeNode root) {
        return getHeight(root);
    }
    public int getHeight(TreeNode node){
        return node == null ? 0 : Math.max(getHeight(node.left), getHeight(node.right)) + 1;
    }
}
```