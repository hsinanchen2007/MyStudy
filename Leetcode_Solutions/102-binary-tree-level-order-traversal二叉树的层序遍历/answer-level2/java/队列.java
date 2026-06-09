这道题就是一道层序遍历的模板题，我们必须知道使用队列来实现树的层序遍历，由于答案是要输出一层一层的值，那我们就使用一个size，记录当前层有多少个节点，并在添加当前层的这些节点的过程中将下一层的节点也放到队列中去就ok了
<br>
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue=new LinkedList<TreeNode>();
        
        List<List<Integer>> res=new ArrayList<>();
        if(root==null) return res;
        
        queue.add(root);
        
        while(!queue.isEmpty()){
            //获得此时这一层的节点个数
            int size=queue.size();
            List<Integer> cur=new ArrayList<>();
            
            while(size!=0){
                TreeNode node=queue.poll();
                cur.add(node.val);
                
                if(node.left!=null) queue.add(node.left);
                if(node.right!=null) queue.add(node.right);
                
                size--;
            }
            
            res.add(cur);
        }
        
        return res;
    }
}
```