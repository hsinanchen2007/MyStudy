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
    //DFS前序遍历
    // List<List<Integer>> levels=new ArrayList();

    // public List<List<Integer>> levelOrder(TreeNode root) {
    //     if(root==null)
    //         return levels;
    //     help(root,0);
    //     return levels;
    // }

    // private void help(TreeNode node,int level){
    //     if(levels.size()==level)
    //         levels.add(new ArrayList());
        
    //     levels.get(level).add(node.val);

    //     if(node.left!=null)
    //         help(node.left,level+1);
    //     if(node.right!=null)
    //         help(node.right,level+1);
    // }

    //BFS
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root==null)
            return new ArrayList();
        List<List<Integer>> res = new ArrayList();
        Queue<TreeNode> queue = new LinkedList();
        queue.add(root);
        while(!queue.isEmpty()){
            int count=queue.size();
            List<Integer> list = new ArrayList();
            while(count>0){
                TreeNode node = queue.remove();
                list.add(node.val);
                if(node.left!=null)
                    queue.add(node.left);
                if(node.right!=null)
                    queue.add(node.right);
                count--;
            }
            res.add(list);
        }
        return res;
    }
}
```
