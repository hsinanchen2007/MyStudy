### 解题思路

解题的思路还是比较简单的

1. 判断当前节点为null就返回false
2. 如果sum已经是0并且是已经是叶子节点，则说明已经找到解，返回true
3. 其他情况则递归处理左右子树，同时将sum减去当前节点值

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
        if (root == null) {
            return false;
        }
        if (sum == root.val && root.left == null && root.right == null) {
            return true;
        }
        return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);
    }
}
```