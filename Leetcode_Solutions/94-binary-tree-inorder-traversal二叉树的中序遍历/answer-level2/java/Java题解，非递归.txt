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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<Integer>();
        if(root==null) return res;
        Stack<TreeNode> stack = new Stack<TreeNode>();
        while(true){
            while(root!=null){
                stack.push(root);
                root=root.left;
            }
            if(stack.isEmpty()){
                break;
            } 
            root = stack.pop();
            res.add(root.val);
            root=root.right;   // 不要进行null判断，直接赋值，避免上面第二个while进入死循环
        }
        return res;
    }
}
```
