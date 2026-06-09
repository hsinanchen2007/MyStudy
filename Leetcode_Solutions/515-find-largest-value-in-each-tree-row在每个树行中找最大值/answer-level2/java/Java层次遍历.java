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
        List<Integer> rlist = new ArrayList<>();
        if(root==null) return rlist;
        
        List<TreeNode> nodeList = new LinkedList<>();
        nodeList.add(root);
        while(!nodeList.isEmpty()){
            int size = nodeList.size();
            int max = nodeList.get(0).val;
            for(int i = 0;i< size;i++){
                TreeNode node = nodeList.remove(0);
                max = Math.max(node.val,max);
                if(node.left!=null) nodeList.add(node.left);
                if(node.right!=null) nodeList.add(node.right);

            }
            rlist.add(max);
        }
        return rlist;
        
    }
}
```