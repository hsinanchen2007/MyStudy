```
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> lists=new ArrayList<>();
        Queue<TreeNode> queue=new LinkedList<>();
        if(root==null) return lists;
        queue.add(root);
        int len=1;
        while(queue.size()!=0){
            int l=len;//l代表当前层次的节点个数
            len=0;//len代表下一层的节点个数
            List<Integer> list=new ArrayList<>();
            for(int i=0;i<l;i++){
                TreeNode t=queue.poll();
                list.add(t.val);
                if(t.left!=null){
                    queue.add(t.left);
                    len++;
                }
                if(t.right!=null){
                    queue.add(t.right);
                    len++;
                }
            }
            lists.add(list);
        }
        Collections.reverse(lists);
        return lists;
    }
}
```
