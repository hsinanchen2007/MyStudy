public boolean hasPathSum(TreeNode root, int sum) { 
        // 迭代DFS
         if(root == null) return false;
         LinkedList<Pair<TreeNode, Integer>> list = new LinkedList<>();
         list.add(new Pair(root, root.val));
        
         while(! list.isEmpty()){
             Pair<TreeNode, Integer> cur = list.pollLast();
             int cur_sum = cur.getValue();
             TreeNode cur_node = cur.getKey();
             if(cur_node.left == null && cur_node.right == null && cur_sum == sum) return true;
             if(cur_node.left != null) list.add(new Pair(cur_node.left, cur_node.left.val + cur_sum));
             if(cur_node.right != null) list.add(new Pair(cur_node.right, cur_node.right.val + cur_sum));
         }
        return false;
}