### 解题思路
队列可以求得左右子树的高度
递归是分别判断，所有的子树都得满足是平衡树，整个树才是平衡树

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
    LinkedList queen = new LinkedList<>();

    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (Math.abs(height(root.left) - height(root.right)) > 1) {
            return false;
        }
        return isBalanced(root.left) && isBalanced(root.right);
    }

    private int height(TreeNode root) {
        if (root == null) {
            return 0;
        }
        queen.add(root);
        int level = 0;
        while (!queen.isEmpty()) {
            int size = queen.size();
            for (int i = 0; i < size; i++) {
                TreeNode treeNode = (TreeNode) queen.poll();
                if (treeNode.left != null) {
                    queen.add(treeNode.left);
                }
                if (treeNode.right != null) {
                    queen.add(treeNode.right);
                }
            }
            level++;
        }
        return level;
    }
}
```