### 解题思路
先遍历A树，直到找到和B树的root相同的节点，再同时遍历A、B树并对比。

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
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if (B == null)
            return false;
        return searchBinaryTree(A, B);
    }

    public boolean searchBinaryTree(TreeNode root, TreeNode target) {
        if (root == null)
            return false;
        // 再A中找到和B相同的节点，开始从此节点开始同时遍历A、B树
        if (root.val == target.val) {
            return compare(root, target);
        }
        return searchBinaryTree(root.left, target) || searchBinaryTree(root.right, target);
    }

    public boolean compare(TreeNode A, TreeNode B) {
        if (B == null)
            return true;
        if (A == null || A.val != B.val)
            return false;
        return compare(A.left, B.left) && compare(A.right, B.right);
    }
}
```