### 解题思路
本题目的是将searching tree反向遍历，但由于TreeNode结构没有存放parent节点信息，为了减少遍历次数我们将整个树看作多个子树。
我们进行反向遍历，每次遍历一个子树时，将根节点的值 += right tree的所有值的和(最左叶子节点的值)，左节点的值 += root的值。

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
    public TreeNode bstToGst(TreeNode root) {
        bst(root, 0);
        return root;
    }

    private int bst(TreeNode root, int parentValue) {
        if (root.right == null) {
            root.val += parentValue;
        }
        if (root.right == null && root.left == null) {
            return root.val;
        }
        if (root.right != null) {
            root.val += bst(root.right, parentValue);
        }
        if (root.left != null) {
            return bst(root.left, root.val);
        } 
        return root.val;
    }
}
```