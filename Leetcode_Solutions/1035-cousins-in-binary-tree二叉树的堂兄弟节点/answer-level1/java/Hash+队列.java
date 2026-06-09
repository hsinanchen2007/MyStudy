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
		     public boolean isCousins(TreeNode root, int x, int y) {

	         if(root== null ){
	            return false;
	         }
	         Queue<TreeNode> queue = new LinkedList();
	         queue.add(root);
	         while(!queue.isEmpty()){
	            int curNum = queue.size();
	            HashMap<Integer , TreeNode> hashset = new HashMap();
	            for(int i = 0 ; i <curNum; i ++ ) {
                    TreeNode node = queue.poll();
	             
                    if(node.left!=null){
                        queue.offer(node.left);
                        hashset.put(node.left.val, node );
                    }
                    if(node.right!=null){
                        queue.offer(node.right);
                         hashset.put(node.right.val, node );
                     }
	            }
	            if(hashset.containsKey(x)&& hashset.containsKey(y) && (hashset.get(x).val!= hashset.get(y).val)){
	                return true;
	            }
	         }
	         return false;

	    }
}