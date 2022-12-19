### 解题思路
递归条件：
root.left为平衡二叉树且root.right为平衡二叉树且高度相差小于等于1，则root为平衡二叉树。
辅助方法：获取树的深度

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
        if(root == null) return true;
        return isBalanced(root.left) && isBalanced(root.right) && (Math.abs(depth(root.left)-depth(root.right)) <= 1);
    }
    private int depth(TreeNode root){
        return root == null ? 0 : (Math.max(depth(root.left),depth(root.right))+1);
    }
}
```