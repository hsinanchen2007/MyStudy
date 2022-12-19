### 解题思路
此处撰写解题思路

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
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root = null;
        if (preorder == null || preorder.length == 0) {
            return root;
        }

        root = new TreeNode(preorder[0]);
        // 题目给的是前序遍历，因此第一个肯定是root节点，那么比root节点值小的肯定是左子树，剩下的是右子树
        // 先在剩下的数组元素里找到左、右子树分界点
        int i = 1;
        while (i < preorder.length && preorder[i] < preorder[0]) {
            i++;
        }

        // 有可能全部都是右子树
        if (i > 1) {
            // 左子树的数组满足下一趟递归条件
            int[] destOrder = new int[i - 1];
            System.arraycopy(preorder, 1, destOrder, 0, i - 1);
            root.left = bstFromPreorder(destOrder);
        }

        // 有可能全部都是左子树
        if (i < preorder.length) {
            int[] destOrder = new int[preorder.length - i];
            System.arraycopy(preorder, i, destOrder, 0, preorder.length - i);
            root.right = bstFromPreorder(destOrder);
        }
        return root;
    }
}
```