### 解题思路
1. 只要左右子树都平衡那这棵树就平衡
2. 是否平衡利用平衡树的定义来判断
3. 左右子树的高度计算借鉴 104 号题的方法即可
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
    public boolean isBalanced(TreeNode root) {
        if (root == null)
            return true;
        if (Math.abs(calculateTreeHeight(root.left) - calculateTreeHeight(root.right)) > 1) {
            return false;
        }
        return isBalanced(root.left) && isBalanced(root.right);
    }
    private int calculateTreeHeight(TreeNode root) {
        if (root == null)
            return 0;
        int leftHeight = calculateTreeHeight(root.left) + 1;
        int rghtHeight = calculateTreeHeight(root.right) + 1;
        return Math.max(leftHeight, rghtHeight);
    }
}
```