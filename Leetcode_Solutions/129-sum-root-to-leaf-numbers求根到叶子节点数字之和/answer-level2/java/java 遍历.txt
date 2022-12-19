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
    int result = 0;
    public int sumNumbers(TreeNode root) {
        if(root!=null){
            traverse(root,0);
        }
        return result;
    }

    private void traverse(TreeNode root, int curarent){
         if(root.left==null&&root.right==null){
      current = current*10+root.val;
      result += current;
      return;
    }
        current = current*10+root.val;
        if(root.left!=null){
        traverse(root.left,current);
        }
        if(root.right!=null){
        traverse(root.right,current);
        }
    }
}
```
