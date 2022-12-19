
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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new LinkedList();
        if(root == null) return res;
        
        Stack<List<Integer>> st = new Stack();
        Queue<TreeNode> q = new LinkedList();
        q.add(root);
        
        while(!q.isEmpty()){
            int len = q.size();
            List<Integer> path = new LinkedList();
            for(int i = 0; i < len; i++){
                TreeNode tmp = q.remove();
                path.add(tmp.val);
                if(tmp.left != null) q.add(tmp.left);
                if(tmp.right != null) q.add(tmp.right);
            }
            st.push(path);
        }
        
        while(!st.isEmpty()){
            res.add(st.pop());
        }
        
        return res;
        
    }
}
```