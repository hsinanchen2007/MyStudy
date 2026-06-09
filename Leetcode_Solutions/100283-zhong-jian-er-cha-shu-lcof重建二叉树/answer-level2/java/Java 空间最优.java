### 解题思路
考察二叉树的先序中序后序遍历。

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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || inorder == null || preorder.length == 0) {
            return null;
        }
        if (preorder.length != inorder.length) {
            return null;
        }

        TreeNode root = new TreeNode(preorder[0]);
        int i = 0;
        while (i < inorder.length && inorder[i] != preorder[0]) {
            i++;
        }
        if (i == inorder.length) {
            return null;
        }
        root.left = buildTree(Arrays.copyOfRange(preorder, 1, i + 1),
                            Arrays.copyOfRange(inorder, 0, i));
        root.right = buildTree(Arrays.copyOfRange(preorder, i + 1, preorder.length),
                            Arrays.copyOfRange(inorder, i + 1, inorder.length));
        return root;
    }
}
```