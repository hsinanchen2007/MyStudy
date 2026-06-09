### 解题思路
java递归求解。直径代表的最长路径可能经过跟节点、也有可能不经过根节点只在left或right子树。

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

    private int max=0;

    public int depthofTree(TreeNode root){
        if(root==null) return 0;
        int depl = depthofTree(root.left);
        int depr = depthofTree(root.right);
        max = Math.max(max, depl+depr);
        return Math.max(depl,depr)+1;
    }

    public int diameterOfBinaryTree(TreeNode root) {
        depthofTree(root);
        return max;
    }
}
```