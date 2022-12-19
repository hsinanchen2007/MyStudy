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
    public int deepestLeavesSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Stack<TreeNode> stack = new Stack<>();        
        stack.push(root);
        int res = 0;
        while (!stack.isEmpty()) {
            Stack<TreeNode> temp = new Stack<>();
            int tempSum = 0;
            while (!stack.isEmpty()) {
                TreeNode root1 = stack.pop();
                tempSum += root1.val;
                if (root1.left != null) {
                    temp.push(root1.left);
                }
                if (root1.right != null) {
                    temp.push(root1.right);
                }
            }
            if (temp.isEmpty()) {
                res = tempSum;
                break;
            }
            stack = temp;
        }
        return res;
    }

}
```