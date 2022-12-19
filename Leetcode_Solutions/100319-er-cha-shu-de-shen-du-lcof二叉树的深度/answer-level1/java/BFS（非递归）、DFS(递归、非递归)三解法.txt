```
    /**
     *  递归版本
     */
    public int maxDepth_1(TreeNode root) {
        if(root==null) return 0;
        return Math.max(maxDepth_1(root.left),maxDepth_1(root.right))+1;
    }

    /**
     * 非递归BFS
     */
    public int maxDepth_2(TreeNode root) {
        if(root==null) return 0;
        Queue<TreeNode> queue=new LinkedList<TreeNode>();
        int depth=0;
        queue.add(root);
        while(!queue.isEmpty()){
            int size=queue.size();
            while(size>0){
              TreeNode node= queue.poll();
              if(node.left!=null){
                  queue.add(node.left);
              }
              if(node.right!=null){
                  queue.add(node.right);
              }
              size--;
            }
            depth++;
        }
        return depth;
    }

    /**
     * 非递归DFS
     */
    public int maxDepth(TreeNode root) {
        if(root==null) return 0;
        Stack<Record> stack=new Stack<Record>();
        int maxDepth=0;
        stack.add(new Record(1,root));
        while(!stack.isEmpty()){
           Record rec= stack.pop();
           TreeNode node= rec.node;
           int level=node.val;
           if(node.left==null && node.right==null) maxDepth=Math.max(maxDepth,level);
           if(node.right!=null){
               stack.add(new Record(level+1,node.right));
           }
           if(node.left!=null){
               stack.add(new Record(level+1,node.left));
           }
        }
        return maxDepth;
    }

    class Record{
        int level;
        TreeNode node;

        public Record(int level, TreeNode node) {
            this.level = level;
            this.node = node;
        }
    }
```
