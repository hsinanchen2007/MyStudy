```java []
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
    public boolean hasPathSum(TreeNode root, int sum) 
    {
        if (root == null){
            return false;
        }
        
        Stack<TreeNode> stack = new Stack<>();
        Stack<Integer> sumStack = new Stack<>();
        
        stack.push(root);
        sumStack.push(sum - root.val);
        
        while(!stack.isEmpty()) 
        {
            TreeNode node = stack.pop();
            int currSum = sumStack.pop();
            
            if (node.left == null && node.right == null && currSum == 0){
                return true;
            }
            
            if (node.right != null){
                stack.push(node.right);
                sumStack.push(currSum - node.right.val);
            }
            
            if (node.left != null){
                stack.push(node.left);
                sumStack.push(currSum - node.left.val);
            }
        }
        return false;
    }
}
```
