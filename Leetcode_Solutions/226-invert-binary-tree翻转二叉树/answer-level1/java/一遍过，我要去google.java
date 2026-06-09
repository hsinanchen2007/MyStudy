### 解题思路
递归思路 言简意赅

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
    public TreeNode invertTree(TreeNode root) {
        //递归写法
        if (root == null) {
            return root;
        }
        
        //保存头指针
        TreeNode head = root;
        
        //递归翻转二叉树
        invertBinaryTree(head);

        return root;
    }

    //递归翻转二叉树
    private void invertBinaryTree (TreeNode node) {
        if (node == null) {
            return;
        }
        //交换node的左右节点 使用中间变量
        TreeNode temp = node.left;
        node.left     = node.right;
        node.right    = temp;

        //递归左子树
        invertBinaryTree(node.left);
        //递归右子树
        invertBinaryTree(node.right);
    }
}
```