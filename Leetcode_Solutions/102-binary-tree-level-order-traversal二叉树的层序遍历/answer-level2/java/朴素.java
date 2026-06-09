```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        if(root == null)
            return new LinkedList<>();
        queue.add(root);
        List<List<Integer>>  res= new LinkedList<>();
        while(queue.size() != 0){
            List<Integer> temp = new LinkedList<>();
            int size = queue.size();
            for(int i=0;i<size;i++){
                TreeNode curr = queue.poll();
                temp.add(curr.val);
                if(curr.left != null) queue.add(curr.left);
                if(curr.right != null) queue.add(curr.right);
            }
            res.add(temp);
        }
    return res;
    }
}
```
