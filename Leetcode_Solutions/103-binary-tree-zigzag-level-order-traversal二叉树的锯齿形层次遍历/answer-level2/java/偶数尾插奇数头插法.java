```
 public List<List<Integer>> zigzagLevelOrder(TreeNode root) {

        ArrayList<List<Integer>> lists = new ArrayList<>();
        if (root==null)
            return lists;
        Queue<TreeNode> queue= new LinkedList<>();
        int level=0;
        queue.add(root);

        while (!queue.isEmpty()){
            ArrayList<Integer> list = new ArrayList<>();
            int size = queue.size();
            for (int i=0;i<size;i++){
                TreeNode node = queue.poll();
                if ((level&1)==1){
                    //奇数
                    list.add(0,node.val);
                }else{
                    list.add(node.val);

                }
                if (node.left!=null)
                    queue.add(node.left);
                if (node.right!=null)
                    queue.add(node.right);
            }
            level++;
            lists.add(list);
        }
        return lists;
    }
```
