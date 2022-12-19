##写的不好请大家谅解 
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        
        
        List<List<Integer>> ans = new ArrayList<>();
        if(root==null) return ans;
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        TreeNode cur = null;
        boolean flag = true;//true的话从左到右，false的话从右到左
        while(!queue.isEmpty()){
            //装入当前层的所有节点的val
            List<Integer> list = new ArrayList();
            //装入当前层的下一层的所有节点，用于下一次遍历
            LinkedList<TreeNode> sub = new LinkedList<>();
            while(!queue.isEmpty()){
                if(flag){
                    //从左到右，从第一个开始取
                    cur = queue.removeFirst();
                    list.add(cur.val);
                    //装入节点的顺序都是一致的
                    if(cur.left!=null) sub.add(cur.left);
                    if(cur.right!=null) sub.add(cur.right);
                }else{//从右到左开始取
                    cur = queue.removeLast();
                    list.add(cur.val);
                    //装入节点的顺序都是一致的
                    if(cur.right!=null) sub.addFirst(cur.right);
                    if(cur.left!=null) sub.addFirst(cur.left);
                }
               
            }
            //更换标记，
            flag = !flag;
            //将遍历每一层后的结果装入ans中
            ans.add(list);
            //替换queue，进行下一层的遍历
            queue = sub;
        }
        return ans;
    }
}