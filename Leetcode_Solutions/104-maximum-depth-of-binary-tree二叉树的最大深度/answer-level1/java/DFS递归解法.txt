### 解题思路
采用递归的方式，每次将自己看成当前节点，如果我们是当前节点，我们需要知道是我左子树的高度和右子树的高度，并且将这两个高度进行大小比较，返回大的值。

每次递归首先要寻找递归终止的条件：当递归至叶子节点的子节点，也就是空节点时，停止递归，并返回当前高度值为0
其次是递归主干
最后返回大小比较的结果

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
        if(root == null) return 0;
        
        return getMaxDepth(root);

    }

    public int getMaxDepth(TreeNode root){
        if(root == null) return 0;

        int leftDepth = getMaxDepth(root.left);
        int rightDepth = getMaxDepth(root.right);

        return Math.max(leftDepth, rightDepth) + 1;
    }
}
```