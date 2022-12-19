代码：

```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        ArrayList<List<Integer>> result = new ArrayList<List<Integer>>();
        ArrayList<Integer> list = new ArrayList<>();
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        Queue<TreeNode> qtp = new LinkedList<TreeNode>();
        
        while(q.peek()!=null){
            TreeNode node = q.poll();//first
            list.add(node.val);
            
            if(node.left!=null) qtp.offer(node.left);//add
            if(node.right!=null) qtp.offer(node.right);//add
            
            if(q.peek()==null){//下一层
                result.add(list);
                list = new ArrayList<>();//not clear
                q=qtp;
                qtp = new LinkedList<TreeNode>();//
            } 
        }
        
        return result;
    }
}
```
