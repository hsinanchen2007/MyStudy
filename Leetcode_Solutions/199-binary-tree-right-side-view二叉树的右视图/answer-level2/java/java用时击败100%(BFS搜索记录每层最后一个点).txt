这个和二叉树的层序遍历区别在于,只需要保存最右边的TreeNode即可
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
    public List<Integer> rightSideView(TreeNode root) {
        //这个和二叉树的层序遍历区别在于,只需要保存最右边的TreeNode即可
        List<Integer>list=new ArrayList<Integer>();
        if(root==null)
            return list;
        int level=0;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
       while ( !queue.isEmpty() ) {
           int level_length = queue.size();
          for(int i = 0; i < level_length; ++i) {
              if(i==level_length-1){
                  list.add(queue.peek().val);
              }
            TreeNode node = queue.remove();
            
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
            
          }
           
       level++;
}
return list;
        
    }
}
```
