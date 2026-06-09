```
    //二叉树锯齿形遍历
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        List<LinkedList<Integer>> res = new ArrayList<>();
        if(root != null){
            process(root,res,0);
            for (LinkedList<Integer> re : res) {
                ans.add(re);
            }
        }
        return ans;
    }

    private void process(TreeNode root, List<LinkedList<Integer>> res, int level) {
        if(res.size() == level){
            res.add(new LinkedList<Integer>());
        }
        if(level % 2 != 0){
            res.get(level).addFirst(root.val);
        }else{
            res.get(level).addLast(root.val);
        }
        if(root.left != null){
            process(root.left,res,level+1);
        }
        if(root.right != null){
            process(root.right,res,level+1);
        }
    }
```