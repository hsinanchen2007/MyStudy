### 解题思路
循环节点，遍历左右子树，判断对应位置是否相等。

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
    public boolean isSymmetric(TreeNode root) {
        //排除空树情况
        if (root == null) return true;
        return dfs(root.left, root.right);
    }

    public boolean dfs(TreeNode left, TreeNode right){
        //判断是否都结束
        if (left == null && right == null) return true;
        //判断是否不对称
        if (left == null || right == null) return false;
        //判断值是否相等
        if (left.val != right.val) return false;

        return dfs(left.right, right.left) && dfs(left.left, right.right);
    }
}
```