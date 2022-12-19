class Solution {
   //迭代，队列
  public int maxDepth(TreeNode root) {
    Queue<TreeNode> queue = new LinkedList<TreeNode>();
      if(root == null) return 0;
      int depth = 0;
      queue.add(root);
      while(!queue.isEmpty()){
          int size = queue.size();
          depth++;
          for(int i = 0; i < size; i++){
              TreeNode node1 = queue.remove();
              if(node1.left != null ) queue.add(node1.left);
              if(node1.right != null ) queue.add(node1.right);
          }
      }
      return depth;
  }
}

