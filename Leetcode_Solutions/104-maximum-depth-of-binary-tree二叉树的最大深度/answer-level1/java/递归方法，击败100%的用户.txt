### 解题思路
就是简单的递归方法，利用二叉树的最大深度，一定是左右子树深度中最大的一个。其实可以不必多定义一个方法，以前坏习惯的遗留吧。。 待改进

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
    public static int maxDepth(TreeNode root) {
        if(root==null) return 0;
        int maxDepth = maxDepth(root, 0);
        return maxDepth;
    }

    public static int maxDepth(TreeNode root, int depth){
        if(root == null){
            return depth;
        }
        depth++;
        int leftLength = maxDepth(root.left, depth);
        int rightLength = maxDepth(root.right, depth);
        return Math.max(leftLength, rightLength);
    }
}
```