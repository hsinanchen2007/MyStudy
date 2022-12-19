使用重载函数来进行递归，传入root和初始和0.
- 递归终止条件：到达叶子节点，直接返回sum + 当前叶子节点的值
- 递归过程：由于每递归一层，之前的和都要扩大10，因此在递归过程中，需要将现有的和乘以10作为sum传入，将左右子树的递归结果相加。
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
    public int sumNumbers(TreeNode root) {
        return sumNumbers(root,0);
    }
    private int sumNumbers(TreeNode root,int sum){
        if(root == null){
            return 0;
        }
        if(root.left == null && root.right == null){
            return sum + root.val;
        }else{
            return sumNumbers(root.left,(sum + root.val) * 10) + sumNumbers(root.right,(sum + root.val) * 10);
        }
    }
}
```
