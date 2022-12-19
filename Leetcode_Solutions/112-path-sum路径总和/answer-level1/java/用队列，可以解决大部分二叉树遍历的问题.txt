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
        public boolean hasPathSum(TreeNode root, int sum) {
        Queue<TreeNode> queue = new LinkedList<>();
        if (root == null)
            return false;
        queue.add(root);
        while (!queue.isEmpty()){
            TreeNode temp =queue.poll();
            if (temp.left == null && temp.right == null &&temp.val ==sum)
                return true;
            if(temp.left !=null){
                temp.left.val += temp.val;
                queue.add(temp.left);
            }
            if(temp.right !=null){
                temp.right.val += temp.val;
                queue.add(temp.right);
            }
        }
            return false;
    }
}
```
虽然不怎么快