注意左叶子节点的判定，当遇到左叶子节点，就将值加到return语句中。
```
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
    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null){
            return 0;
        }
        int tempSum = 0;
        if(root.left != null && root.left.left == null && root.left.right == null){
            tempSum = root.left.val;
        }
        return tempSum + sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
    }
}
```
