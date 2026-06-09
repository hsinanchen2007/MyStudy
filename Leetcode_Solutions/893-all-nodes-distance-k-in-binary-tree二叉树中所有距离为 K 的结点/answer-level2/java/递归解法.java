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
    HashMap<TreeNode, TreeNode> map = new HashMap<TreeNode, TreeNode>();
    Set s = new HashSet<TreeNode>();
    public void dfs(TreeNode root){
        if(root != null){
            if(root.right != null){
                map.put(root.right, root);
            }
            if(root.left != null){
                map.put(root.left, root);
            }
            dfs(root.left);
            dfs(root.right);
        }
    }
    
    public void search(int K, TreeNode target, List<Integer> ans){
        if (K == 0 || target == null){
            if(target != null){
                if (!s.contains(target)){
                    ans.add(new Integer(target.val));
                }
            }
            return;
        }
        s.add(target);
        if(!s.contains(target.left)){
            search(K-1, target.left, ans);
        }        
        if(!s.contains(target.right)){
            search(K-1, target.right, ans);
        }
        if(!s.contains(map.get(target))){
            search(K-1, map.get(target), ans);
        }
    }
    
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        if(target == null){return null;}
        List<Integer> ans = new ArrayList<Integer>();

        map.put(root, null);
        dfs(root);
        
        search(K, target, ans);
        
        return ans;
    }
}