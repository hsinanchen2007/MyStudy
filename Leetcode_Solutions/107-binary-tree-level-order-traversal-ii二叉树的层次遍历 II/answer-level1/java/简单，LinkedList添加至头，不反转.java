就酱紫。
```
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Queue<TreeNode> Q = new LinkedList<>();
        LinkedList<List<Integer>> seq = new LinkedList<>();
        if(root == null)
            return seq;
        Q.add(root);
        while(!Q.isEmpty()){
            List<Integer> temp = new ArrayList<Integer>();
            int len = Q.size();
            for(int i = 0; i < len; i++){
                TreeNode cur = Q.poll();
                temp.add(cur.val);
                if(cur.left != null)
                    Q.add(cur.left);
                if(cur.right != null)
                    Q.add(cur.right);
            }
            seq.addFirst(temp);
        }
        return seq;
    }
}
```
