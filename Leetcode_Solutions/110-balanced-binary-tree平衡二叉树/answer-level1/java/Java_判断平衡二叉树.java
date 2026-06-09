### 解题思路
1. 首先判断root是否为空，空则返回true
2. 计算root的左子树与右子树的高差，高差应该小于等于1，否则不是平衡二叉树
3. 最后再判断左子树和右子树

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
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        //先判断根是否平衡  再判断左子树 右子树
        boolean flag=Math.abs(height(root.left)-height(root.right))<=1;
        return flag&&isBalanced(root.left)&&isBalanced(root.right);
    }

    public int height(TreeNode root) {
        if(root==null) return 0;
        int left=height(root.left);
        int right=height(root.right);
        return 1+Math.max(left,right);
    }
}
```