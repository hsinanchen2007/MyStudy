### 解题思路
1，如果root为null，则返回null；
2，如果root的val为key，并且左右都为null，则返回null。
3，如果root的val为key，左为null，右不为null，则设置root为root.right.返回root
4, 如果root的val为key,左不为null,右为null,则设置root为root.left,返回root
5, 如果root的val为key,且左右都不为null, 则在左分支找到最大值,设置root.val为最大值,然后在做分支删除这个值为最大值的节点,然后返回
6, 如果root的val不为key,如果大于key,则递归删除左节点中的值,返回root.
7, 如果root的val不为key,如果小于key,则递归删除右节点中的值,返回返回root.


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
public TreeNode deleteNode(TreeNode root, int key) {
        /**
         * 1，如果root为null，则返回null；
         * 2，如果root的val为key，并且左右都为null，则返回null。
         * 3，如果root的val为key，左为null，右不为null，则设置root为root.right.返回root
         * 4, 如果root的val为key,左不为null,右为null,则设置root为root.left,返回root
         * 5, 如果root的val为key,且左右都不为null, 则在左分支找到最大值,设置root.val为最大值,然后在做分支删除这个值为最大值的节点,然后返回
         * 6, 如果root的val不为key,如果大于key,则递归删除左节点中的值,返回root.
         * 7, 如果root的val不为key,如果小于key,则递归删除右节点中的值,返回返回root.
         */
        if (root == null) return null;
        if (root.val == key) {
            if (root.left == null && root.right == null) {
                return null;
            } else if (root.left == null && root.right != null) {
                root = root.right;
                return root;
            } else if (root.left != null && root.right == null) {
                root = root.left;
                return root;
            } else {
                // 左右都不为null
                int left_max = findMaxLeft(root.left);
                root.val = left_max;
                root.left = deleteNode(root.left, left_max);
                return root;
            }
        } else if (root.val > key) {
            root.left = deleteNode(root.left, key);
            return root;
        } else if (root.val < key) {
            root.right = deleteNode(root.right, key);
            return root;
        }
        return null;
    }

    private int findMaxLeft(TreeNode left) {
        if (left == null) return 0;
        if (left.right == null) {
            return left.val;
        }
        return findMaxLeft(left.right);
    }
}
```