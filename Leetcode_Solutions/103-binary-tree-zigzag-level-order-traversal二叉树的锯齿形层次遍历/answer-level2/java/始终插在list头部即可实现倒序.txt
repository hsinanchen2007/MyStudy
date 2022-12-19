```
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> queue=new LinkedList<>();
        List<List<Integer>> answer=new ArrayList<>();
        List<Integer> tmp=new ArrayList<>();
        if(root==null) return answer;
        queue.offer(root);
        int flag=1;
        while(!queue.isEmpty()) {
        	int n_size=queue.size();
        	
        	for(int i=0;i<n_size;i++) {
        		TreeNode tree=queue.poll();
        		if((flag&1)==0) {
        			//双数从右往左
        			tmp.add(0,tree.val);
        		}else {
        			//单数从左往右
        			tmp.add(tree.val);
        		}
        		if(tree.left!=null) queue.add(tree.left);
        		if(tree.right!=null) queue.add(tree.right);
        	}
        	answer.add(new ArrayList<Integer>(tmp));
        	tmp.clear();
        	flag++;
        }
        return answer;
    }
```
