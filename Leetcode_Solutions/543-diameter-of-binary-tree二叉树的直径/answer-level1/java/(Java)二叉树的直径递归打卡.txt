### 解题思路
因为本题要求直径也可以不经过根节点，按我们正常求的二叉树的深度都是经过根节点的，所以定义一个max,用来存储每一个节点左右子树的深度之和，也就是直径。

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
    public int diameterOfBinaryTree(TreeNode root) {
        if(root==null)
        return 0;
        getLength(root);
        return max;
    }
    private int getLength(TreeNode root)
    {
        if(root==null)
        return 0;
        int left=getLength(root.left);
        int right=getLength(root.right);
        max=Math.max(max,left+right);
        return Math.max(left,right)+1;
    }
}
```