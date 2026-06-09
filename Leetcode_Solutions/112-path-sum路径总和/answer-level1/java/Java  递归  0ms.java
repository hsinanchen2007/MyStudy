### 解题思路
思路详见注释

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
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) { //如果root是null，直接返回false
            return false;
        }
        TreeNode left = root.left;
        TreeNode right = root.right;
        if (left == null && right == null && sum == root.val) {
            //当root是叶子节点时（left和right都是null），只有当sum与root节点的值相等时，才满足条件
            return true;
        }
        if (hasPathSum(left, sum - root.val) || hasPathSum(right, sum - root.val)) {
            //当root不是叶子节点时，对左子树和右子树执行递归操作
            return true;
        }
        return false;
    }
}
```