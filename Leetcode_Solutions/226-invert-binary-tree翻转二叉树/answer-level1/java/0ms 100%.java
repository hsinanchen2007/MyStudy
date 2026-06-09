### 解题思路
简单的递归

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
        return helper(root);
    }
    private TreeNode helper(TreeNode node){
        if (node==null)
            return null;

        TreeNode mid=node.left;//交换左右
        node.left=node.right;
        node.right=mid;

        node.left=helper(node.left);//继续递归
        node.right=helper(node.right);
        return node;
    }
}
```