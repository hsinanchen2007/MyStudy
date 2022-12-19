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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> res= new ArrayList<>();
        if(root==null) return res;
        q.add(root);
        int size;
        boolean cnt=true;
        while(!q.isEmpty()){
            ArrayList<Integer> list = new ArrayList<>();
            size = q.size();
            for(int i=0;i<size;i++){
                TreeNode curr = q.poll();
                list.add(curr.val);
                if(curr.left!=null) q.add(curr.left);
                if(curr.right!=null) q.add(curr.right);
                } 
                if(cnt == false){
                    Collections.reverse(list);
                    cnt=true;
                }
                else cnt=false;
            
            res.add(list);
            }
            return res;
        }
        
    }

```
