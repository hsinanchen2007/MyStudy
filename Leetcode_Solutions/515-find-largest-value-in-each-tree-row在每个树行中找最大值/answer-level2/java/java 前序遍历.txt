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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if(root==null){
            return result;
        }
       traverse(root,0,result);
       return result;

    }

    private void traverse(TreeNode root, int depth, List<Integer> result){
        if(root==null){
            return;
        }
        if(depth>result.size()-1){
            result.add(Integer.MIN_VALUE);
        }
        if(root.val>=result.get(depth)){
            result.set(depth,Math.max(result.get(depth),root.val));
        }
        traverse(root.left,depth+1,result);
        traverse(root.right,depth+1,result);
    }
}
```
