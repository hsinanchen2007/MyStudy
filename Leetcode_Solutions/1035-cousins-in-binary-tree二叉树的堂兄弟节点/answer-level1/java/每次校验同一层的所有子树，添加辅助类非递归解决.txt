### 解题思路
添加辅助类Tree，存储一个子树，并且使用Queue<Tree>,一直迭代遍历当前层的所有子树进行解决。
内存消耗很大，属实笨比解法。。。

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
    private class Tree {
        TreeNode parent;
        TreeNode left;
        TreeNode right;

        public Tree(TreeNode parent) {
            this.parent = parent;
            this.left = parent.left == null ? new TreeNode(-1) : parent.left;
            this.right = parent.right == null ? new TreeNode(-1) : parent.right;
        }

        public boolean isInTree(int x, int y) {
            return (left.val == x && right.val == y) || (left.val == y && right.val == x);
        }

        public boolean isInTree(int value) {
            return (left.val == value) || (right.val == value);
        }
    }

    public boolean isCousins(TreeNode root, int x, int y) {
        if (root == null) {
            return false;
        }
        Queue<Tree> queue = new LinkedList<>();
        queue.add(new Tree(root));
        while (!queue.isEmpty()) {
            List<Tree> trees = new ArrayList<>(queue);
            Tree treeX = null, treeY = null;
            for (Tree tree : trees) {
                if (tree.isInTree(x, y)) {
                    return false;
                }
                if (treeX == null && tree.isInTree(x)) {
                    treeX = tree;
                }
                if (treeY == null && tree.isInTree(y)) {
                    treeY = tree;
                }
                if (treeX != null && treeY != null) {
                    return true;
                }
            }
            queue.clear();
            for (Tree tree : trees) {
                if (tree.left.val != -1) {
                    queue.add(new Tree(tree.left));
                }
                if (tree.right.val != -1) {
                    queue.add(new Tree(tree.right));
                }
            }
        }
        return false;
    }
}
```