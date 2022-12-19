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
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root==null){
            return false;
        }
        // 终止条件
        if (root.left == null && root.right == null) {
            return root.val == sum;
        }
        boolean leftResult = false;
        // 先向左子树遍历
        if (root.left != null) {
            leftResult = hasPathSum(root.left, sum - root.val);
        }
        // 如果成功就立即返回
        if (leftResult) {
            return true;
        }
        // 再看右边子树
        boolean rightResult = false;
        if (root.right != null) {
            rightResult = hasPathSum(root.right, sum - root.val);
        }
        return rightResult;
    }


}
```