### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :36.8 MB, 在所有 Java 提交中击败了5.08%的用户

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
        if(root == null)
            return null;
        //交换该节点的左右子树
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        //分别反转左子树、右子树
        invertTree(root.left);
        invertTree(root.right);
        return root;
    }
    
}
```