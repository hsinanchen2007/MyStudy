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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        if(root==null){
            return res;
        }
        while(true){
            while(root!=null){
                res.add(root.val);
                stack.push(root);
                root=root.left;
            }
            if(stack.isEmpty()){
                break;
            }
            root = stack.pop();
            root = root.right; // 直接赋值，如判断null，会引起第二个while循环死循环
        }
        return res;
    }
}
```
